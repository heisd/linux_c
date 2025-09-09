#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
// usnig header for stat
#include <sys/stat.h>
int main(){
    // stat(const char *pathname,struct stat *buf)
    struct stat st;
    int fd=lstat("file/file_soft",&st);
    if(fd==-1){
        perror("lstat");
        return 0;
    }
    printf("dev:%ld\t,size:%ld\t,uid:%d\t,gid:%d\n",st.st_dev,st.st_size,st.st_uid,st.st_gid);
    printf("st_mode:%o\n",st.st_mode);
    printf("S_IRUSR:%o\n",S_IRUSR);
    // for common flie it is same as stat
    // but for soft link it is different
    // using lstat can point soft link file style
    if((st.st_mode & __S_IFMT)==__S_IFLNK){
        printf("user have soft link file\n");
    }
    // using S_IRUSR and st_mode is using have read permission
    // if it is other permission
    if(st.st_mode & S_IROTH){
        printf("other have read permission\n");
    }
    else{
        printf("other have not read permission\n");
    }
    if(st.st_mode & S_IWOTH){
        printf("other have write permission\n");
    }
    else{
        printf("other have not write permission\n");
    }
    if(st.st_mode & S_IXOTH){
        printf("other have execute permission\n");
    }
    else{
        printf("other have not execute permission\n");
    }
    return 0;
}