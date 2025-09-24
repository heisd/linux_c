//kill 函数
// int kill(pid_t pid,int gig);
// return 0 success
// return -1 errno
// pid>0 发送信号给指定的进程->一般只用这一个
// pid=0 把当前进程组的进程全部杀死
// pid=-1 把当前用户能杀死的进程全部杀死
// 每一个进程都一个进程组长，组长ID与进程组ID相同
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
int main(){
    // 自杀
    kill(getpid(),SIGKILL);
    // 如果没有打印出进程就已经杀死了
    printf("hello world");
    return 0;
}


