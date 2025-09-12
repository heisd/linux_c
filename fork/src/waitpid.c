// 使用wait函数来解决僵尸进程问题
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
// waitpid函数
// 函数原型
// pid_t waitpid(pid_t pid,int *status ,int option);
// 函数作用和wait函数相似
// 函数参数
// pid=-1与wait等效
// pid>0 等待其进程与pid相等的子进程
// pid=0  一般用不到 回收组里面的所有进程
// pid<-1 一般用不到 适用于子进程在其他组的情况
// status 
// option 
// 参数
// 1、 WNOHANG 函数非阻塞
// 2.  0        函数阻塞
// 返回值
// >0 返回回收掉的子进程的PID
// 1  无子进程
// =0 参数3为WNOHANG,而且子进程正在运行
int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        perror("pid");
        return -1;
    }else if(pid>0){
        printf("pid:%d\n",getpid());
        int status;
        int flag=waitpid(-1,&status,WNOHANG);
        if(flag==-1){
            printf("no child is living\n");
        }else if(flag>0){
            printf("wpid =:%d\n",flag);
            // 判断退出状态
            // 常用的退出参数 WIFEXITED WEXITSTATUS
            // WIFSIGNALED WTERMSIG
            if(WIFEXITED(status)){
                printf("success exit,status==%d\n",WEXITSTATUS(status));
            }else if(WIFSIGNALED(status)){
                printf("be killed by signal, signo==%d\n",WTERMSIG(status));
            }
        }else if(flag==0){
            printf("option argv ==WNOHANG && child process is alive");
        }
    }else if(pid==0){
        printf("pid =%d\t,fpid =%d\n",getpid(),getppid());
        sleep(5);
    }

}
