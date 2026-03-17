// 函数原型
// int execl（const char *path,const char *arg,../*(char*)NULL）
// path ->要执行程序的绝对路径
// 变参arg-> 要执行的程序所需要的参数
// arg ->占位，通常写应用程序的名字
// arg 后面 命令参数 
// 参数写完之后NULL
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
int main(){
    pid_t pid;
    pid =fork();
    if(pid<0){
        perror("fork");
        return -1;
    }else if(pid>0){
        printf("this is parent %d\n",getpid());
    }else if(pid==0){
        printf("this is child %d\n",getpid());
        // 1.执行系统命令
        // execl("/bin/ls","ls","-l",NULL);
        // perror("execl error");
        // 2.执行自己编写的可执行程序
        // use relative path to keep this example portable
        execl("../bin/test.exe","test.exe","hello","world",NULL);
        perror("execl error");
        
    }
}
