
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
// 父进程给子进程发送信号
int main(){

  int i=0;
  printf("这是父进程pid为%d\n",getpid());
  for(i;i<3;i++){
    pid_t pid=fork();
    if(pid<0){
      perror("fork");
    }else if(pid==0&&i==0){
        printf("这个是子进程1\n");
        printf("子进程1的pid为:%d\n",getpid());
        sleep(10);
        break;
    }else if(pid==0&&i==1){
        printf("这个是子进程2\n");
        printf("子进程2的pid为:%d\n",getpid());
        sleep(10);
        break;
    }
    else if(pid==0&&i==2){
        printf("这个是子进程3\n");
        printf("子进程3的pid为:%d\n",getpid());
        printf("子进程3要杀死父进程");
        kill(getppid(),SIGKILL);
        sleep(10);
        break;
    }
}
   
    return 0;
}


