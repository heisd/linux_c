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
    int fd=stat("file/file.txt",&st);
    if(fd==-1){
        perror("stat");
        return 0;
    }
    printf("dev:%lld\t,size:%lld\t,uid:%d\t,gid:%d\n",
           (long long)st.st_dev, (long long)st.st_size, st.st_uid, st.st_gid);
    printf("st_mode:%o\n",st.st_mode);
    printf("S_IRUSR:%o\n",S_IRUSR);
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
