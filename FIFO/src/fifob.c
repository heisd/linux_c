#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
    //
    int fd = open("../fifo/fifo1", O_RDWR, 0775);
    if (fd == -1){
        perror("open");
        return -1;
    }
    char buf[64];
    memset(buf, 0, sizeof(buf));
    read(fd, buf, sizeof(buf));
    printf("buf=%s\n", buf);
    close(fd);
    getchar();
}