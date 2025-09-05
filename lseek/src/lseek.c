#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
int main(){
    // file size using iseek
    int fd = open("./file/iseek.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    int len=lseek(fd,0,SEEK_END);
    printf("file size :=%d byte\n",len);
    close(fd);
    return 0;

}