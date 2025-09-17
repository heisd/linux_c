#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
    //使用access来判断文件是否存在
    //返回为0
    //就是文件存在
    if(access("../fifo/fifo1",F_OK)==0){
        printf("该文件存在\n");
    }
    if(access("../fifo/fifo1",W_OK)==0){
        printf("进程有写文件的权限\n");
    }

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
}