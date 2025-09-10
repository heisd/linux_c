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
    int flag=fcntl(fd,F_GETFL,0);
    flag=flag|O_APPEND;
    fcntl(fd,F_SETFL,flag);
    write(fd,"hello world\n",sizeof("hello world\n"));
    return 0;

}