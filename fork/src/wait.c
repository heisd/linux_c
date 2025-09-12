// 使用wait函数来解决僵尸进程问题
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
// wait函数->阻塞型函数
// 函数原型
// pid_t wait(int *status)
// 函数作用：
//  1.函数作用等待子进程退出
//  2.回收子进程残留资源
//  3.获取子进程状态
//  返回值
//  success 清理掉子ID
//  failed -1
//  status参数->传出参数
//  一般没有特殊需要传入NULL
int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        perror("pid");
        return -1;
    }else if(pid>0){
        printf("pid:%d\n",getpid());
        int status;
        int wpid=wait(&status);
        if(wpid==-1){
            perror("wait");
        }else{
            printf("wpid =:%d\n",wpid);
            // 判断退出状态
            // 常用的退出参数 
            // WIFEXITED WEXITSTATUS
            // WIFSIGNALED WTERMSIG
            if(WIFEXITED(status)){
                printf("success exit,status==%d\n",WEXITSTATUS(status));
            }else if(WIFSIGNALED(status)){
                printf("be killed by signal, signo==%d\n",WTERMSIG(status));
            }
        }
    }else if(pid==0){
        printf("pid =%d\t,fpid =%d\n",getpid(),getppid());
        sleep(5);
    }

}
