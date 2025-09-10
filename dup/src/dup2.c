#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
    char cwd[1024];
    if(getcwd(cwd,sizeof(cwd))!=NULL){
        printf("working in cwd %s\n",cwd);
    }
    // open file
    int fd=open("../src/file/readme",O_RDWR|O_CREAT,0755);
    if(fd<0){
        perror("open");
        return -1;
    }
    // copy fd
    // can ponit newfd num
    int newfd=dup2(fd,2);
    printf("fd:%d\n",fd);
    printf("newfd:%d\n",newfd);
    write(fd,"hello world",strlen("hello world"));
    lseek(fd,0,SEEK_SET);
    char buf[64];
    memset(buf,0x00,sizeof(buf));
    int n=read(newfd,buf,sizeof(buf));
    printf("read over buf=%s\n",buf);
    close(fd);
    close(newfd);
    return 0;
}