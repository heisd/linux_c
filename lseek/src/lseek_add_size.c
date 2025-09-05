#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
int main(){
   int fd=open("./file/iseek.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    lseek(fd,100,SEEK_SET);
    // write string to file
    // write one byte
    // using ls shell show file size is 101 bytes
    write(fd, "h",1);
    close(fd);
    return 0;
}