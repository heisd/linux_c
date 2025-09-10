#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
    // dup(fd)==fcntl(fd,F_DUPFD,0)
    int fd=open("../src/file/file.txt",O_RDWR|O_CREAT,0775);
    if(fd<0){
        perror("open");
        return -1;
    }
    int newfd=fcntl(fd,F_DUPFD,0);
    printf("fd=%d\n",fd);
    printf("newfd=%d\n",newfd);
    close(fd);
    close(newfd);
    //changed file flag 

    return 0;
    

}