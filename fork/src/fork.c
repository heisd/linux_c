#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(){
// 参考文档
// 就绪状态->运行状态 获得CPU时间片
// 运行状态->就绪状态 CPU时间片使用完成
// 运行状态->挂起状态 
// 就绪状态->挂起状态 kill SIGNSTOP PID
// 挂起状态->就绪状态 kill SIGNCOUT PID
// 就绪状态->终止状态 kill -9 PID
// 挂起状态->终止状态 
// 运行状态->终止状态 
// fork函数原型
// pid_t fork(void)
// fork的返回值
// 父进程返回的值为子进程的PID,这个值大于0
// 子进程返回的值为0
// 为负数创建失败
    pid_t pid;
    char *message;
    pid=fork();
    if(pid<0){
        perror("fork failed");
        exit(1);
    }
    if(pid==0){
        message="this is the child\n";
        printf("child PId %d,FPID %d\n",getpid(),getppid());
        printf(message);
    }else{
        message="this is the parent\n";
        printf("parent PID %d,FPID %d\n",getpid(),getppid());
        printf(message);
        sleep(1);
    }
    // 被打印两次
    printf("after fork.PID %d\n",getpid());
    return 0;
}