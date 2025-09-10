#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
    int fd =open("../src/file/terimal.txt",O_RDWR|O_CREAT,0777);
    if(fd<0){
        perror("open");
        return -1;
    }
    //using dup2 
    int outfile=dup2(fd,STDOUT_FILENO);
    printf("hello world\n");
    close(fd);
    //why close fd but output in file
    int a=10;
    int b=20;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("a+b=%d\n",a+b);
    return 0;
}