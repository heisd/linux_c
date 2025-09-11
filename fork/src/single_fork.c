#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
int n=0;
int main(){
    pid_t pid;
    // 父子进程不共享全局变量
    // 但是父子进程的地址一样
    // why?
    for (int i = 0; i < 3; i++)
    {
        pid=fork();
        if(i==0){
            if(pid>0){
                printf("this origin parent PID :%d\n",getpid());
                n=3;
                printf("%p\n",&n);
            }
        }
        // in sleep kill father making a single 
        sleep(20);
        if(pid==0){
            // 为了避免父进程没有执行子进程就已经结束了
            sleep(1);
            printf("%dson PID %d\t %dparent PID%d\n",i+1,getpid(),i+1,getppid());
            printf("%d\n",n);
            printf("%p\n",&n);
            break;
        }
    }
    
}