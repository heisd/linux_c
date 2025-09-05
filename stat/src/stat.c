#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(){
    // stat(cosnt char *pathname,struct stat *buf)
    struct stat st;
    int fd=open("file/file.txt",O_RDWR);
    if(fd==-1){
        perror("open");
        return 0;
    }
    printf("dev:%ld\t,size:%ld\t,uid:%d\t,gid:%d\n",st.st_dev,st.st_size,st.st_uid,st.st_gid);

}