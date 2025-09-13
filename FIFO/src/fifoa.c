#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main(){
    
    int fd=open("../fifo/fifo1",O_RDWR,0777);
    if(fd==-1){
        perror("open");
        return -1;
    }
    write(fd,"hello world",strlen("hello world"));
    close(fd);
    // 使用getchar等待程序退出-保证我们使用另一个进程的时候可以成功的使用这个进程
    getchar();
}