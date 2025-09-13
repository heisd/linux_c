// 在兄弟进程里面完成ps aux | grep bash
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
    // 子进程1
    pid_t pid1=fork();
    if(pid1<0){
        perror("pid");
        return -1;
    }else if(pid1==0){
        // 子进程1->实现ps aux输入到写端
        close(fd[0]); 
        dup2(fd[1],STDOUT_FILENO);
        execlp("ps","ps""aux",NULL);
        //execlp("printf","printf","this is child1%d\n",getpid(),NULL);
    }
    // 子进程2
    pid_t pid2=fork();
    if(pid2==0){
        //子进程2->实现grep bash输出到读端
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execlp("grep","grep","bash",NULL);
        //execlp("printf","printf","this is child2%d\n",getpid(),NULL);
        char buf[1024];
        memset(buf,0,sizeof(buf));
        read(fd[0],buf,sizeof(buf));
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);
    printf("兄弟进程之间通信完成\n");


   

  
   


   





}

















