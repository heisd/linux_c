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
    // 加上\n使得可以退出这个read程序
    write(fd,"hello world\n",strlen("hello world\n"));
    // 
    close(fd);
}