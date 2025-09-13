#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    char cwd[1024];
    if(getcwd(cwd,sizeof(cwd))!=NULL){
        printf("文件所在的目录为%s\n",cwd);
    }else{
        perror("cwd");
        return -1;
    }
    // 使用pipe函数
    int fd[2];
    int ret=pipe(fd);
    if(ret<0){
        perror("pipe");
        return -1;
    }
    // 关闭读端写数据会导致什么呢
    close(fd[0]);
    write(fd[1],"hello world",strlen("hello world"));
    // 关闭写端->看看读端会不会阻塞
    // 发现并不阻塞
    // 如果将下面这个关闭写端给注释掉->read函数会阻塞
    // close(fd[1]);
    char buf[64];
    memset(buf,0,sizeof(buf));
    int n=read(fd[0],buf,sizeof(buf));
    printf("read over,n=%d,buf=%s\n",n,buf);
}

















