// pipe适用于父子间通信->管道
// 在Linux系统下，进程之间通信都需要通过内核
// 关系在image文件夹内
// 这种叫进程间通信IPC -> interProcess communication
// 在不同进程之间可以使用不同的方法来进行通信
// 文件，管道，信号，共享内存，消息队列，套接字，命名管道等
// 常用->管道，信号，共享内存,套接字
// 管道的本质是一块内核缓冲区,管道是通过一个环形队列来实现 default size = 4k
// using ulimit -a command to have size
// 由两个文件描述符->一个是读端另一个是写端 
// 数据只可以从写端流到读端->数据的流向是单向的
// 如果实现双向流动要使用两个管道
// 当两个进程都结束的时候，管道也是自动消失
// 管道的读端和写端都是阻塞的
// 管道的数据不可以反复读取
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
    pid_t pid=fork();
    if(pid<0){
        perror("pid");
        return -1;
    }else if(pid>0){
        // 关闭读端
        // fd[0]->read
        // fd[1]->write
        close(fd[0]);
        // read如果没有函数可读的时候就会阻塞
        // 会阻塞5s-> this
        sleep(5);
        write(fd[1],"hello world",sizeof("hello world"));
        // 保证父进程后退出
        wait(NULL);
    }else{
        // 关闭写端
        printf("*******");
        close(fd[1]);
        char buf[1024];
        memset(buf,0,sizeof(buf));
        // this
        read(fd[0],buf,sizeof(buf));
        printf("read over,buf:%s\n",buf);
    }

  
   


   





}

















