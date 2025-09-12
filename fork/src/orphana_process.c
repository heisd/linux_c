#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
// 制作孤儿进程
int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        perror("fork");
        return -1;
    }
    if(pid>0){
        printf("this is parent %d\n",getpid());
    }
    
    if(pid==0){
        //让子进程多睡一会等待父进程死亡
        sleep(10);
        printf("this is son %d\n,its parent is %d\n",getpid(),getppid());
    }
}
//运行上面代码你就会发现制造了一个孤儿进程