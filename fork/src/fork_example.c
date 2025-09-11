#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() { 
    for(int i=0;i<3;i++) {
        pid_t pid = fork();  // 将 fork() 的返回值赋给 pid
        if (pid < 0) {
            perror("fork error");
            return -1;
        }
        if(i==0){
        if (pid > 0) {  // 父进程
            printf("父进程 PID: %d\n", getpid());
        }
    }
        
        if (pid == 0) {  // 子进程
            printf("子进程 PID: %d, 父进程 PID: %d\n", getpid(), getppid());
            break;
        }
    }

    return 0;
}
