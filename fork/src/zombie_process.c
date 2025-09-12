#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
// 制作僵尸进程
// 如何杀死僵尸进程
// 杀死僵尸进程办法
// 使用杀死父进程的方法
// 然后再让init进程领养来进行资源的回收
int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        perror("pid");
        exit(1);
    }else if(pid>0){
        // 让父进程多睡一会等子进程结束
        sleep(10);
        printf("this is parent process%d\n",getpid());
    }else if(pid==0){
        printf("this is child porcess%d\t,its parent is %d\n",getpid(),getppid());
    }

}