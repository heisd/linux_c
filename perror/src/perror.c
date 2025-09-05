#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
int main(){
    int fd=open("./file.txt",O_RDWR);

    if(fd==-1){
        perror("open");
        return 0;
    }
    return 0;

}