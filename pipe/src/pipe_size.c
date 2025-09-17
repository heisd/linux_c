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
    // 使用下面代码或者使用ulimit -a来找管道大小 
    printf("pipe size==%ld\n",fpathconf(fd[0],_PC_PIPE_BUF));
    printf("pipe size==%ld\n",fpathconf(fd[1],_PC_PIPE_BUF));

    

    


}
