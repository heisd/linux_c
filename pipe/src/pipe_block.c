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
    // 把管道设置为非阻塞->读端
    int flag=fcntl(fd[0],F_GETFL,0);
    flag|=O_NONBLOCK;
    fcntl(fd[0],F_SETFL,flag);
    // 如果不设置非阻塞的话，我们运行的话发现程序是阻塞的
    char buf[64];
    memset(buf,0,sizeof(buf));
    int n=read(fd[0],buf,sizeof(buf));
    printf("hello world n=%d\n",n);



}

