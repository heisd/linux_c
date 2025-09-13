// 在父子进程里面完成ps aux | grep bash
// 本来ps aux命令是在终端上输出我们把这个命令放在管道的写端
// grep bash命令放在管道的读端
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
        // 这个时候execlp还没有跑起来所以能正常输出
        printf("文件所在的目录为%s\n",cwd);
    }else{
        perror("cwd");
        return -1;
    }
    // 使用pipe函数-> create pipe
    int fd[2];
    int ret=pipe(fd);
    if(ret<0){
        perror("pipe");
        return -1;
    }
    // create child pipe
    pid_t pid=fork();
    if(pid<0){
        perror("pid");
        return -1;
    }else if(pid>0){
        // 父进程
        // 关闭读端
        // fd[0]->read
        // fd[1]->write
        close(fd[0]);
        // 把这个命令放在管道的写端
        // 使用dup2函数把标准输出放在了写端
        dup2(fd[1],STDOUT_FILENO);
        execlp("ps","ps","aux",NULL);
        perror("execlp ps");
        return -1;
    }else{
        // 子进程
        // 关闭写端
        printf("*******");
        close(fd[1]);
        // 使用dup2函数把标准输入放在了读端
        dup2(fd[0],STDIN_FILENO);
        execlp("grep","grep","bash",NULL);
        perror("execlp grep");
        return -1;
     
    }
    // 我们在调用dup函数把标准输出回到终端上看看会发生什么
    // 为啥标准输出没有回来呀
    // 我询问deepseek，他给我的回复是execlp会替换掉整个进程,后面的不会执行
    // 他给我的建议是在父进程wait(NULL)前输出，而且建立了两个子进程，分别来实现ps aux 和grep bash
    dup2(STDOUT_FILENO,fd[1]);
    printf("hello world");
   

  
   


   





}

















