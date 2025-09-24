#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
// 什么是信号
// 信号是我们在linux/unix上的一种通信方式
// 
// 熟练使用信号来完成有子进程的回收
// signal函数
// 函数作用
// 注册信号捕捉函数
// 函数原型
// typedef void (*sighandler_t)(int);
// sighandler_t signal(int signnum,sighandler_t handler)

// 编写信号处理函数
// 打印信号编号
// 使用kill -l命令可以看到我们的信号编号对应的信号数
void sighandler(int signo){
    printf("signo=%d\n",signo);
}
int main(){
    // 使用管道，如果我们的读端关闭，在写端还写有数据
    // 内核会给我们返回有一个信号 SIGPIPE信号
    int fd[2];
    int ret=pipe(fd);

    if(ret==-1){
        perror("pipe");
        return -1;
    }
    // 注册信号SIGPIPE函数
    signal(SIGPIPE,sighandler);
    // 关闭读端
    close(fd[0]);
    // 在写端写入hello world
    write(fd[1],"hello world",strlen("hello world"));

    return 0;

    
    





}