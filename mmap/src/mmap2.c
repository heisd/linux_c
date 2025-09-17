// mmap函数原型
// void *mmap（void *addr,size_t length,int prot,int flags,int fd,off_t offfset）
// addr让内核去指定一个内存起始地址--一般使用NULL
// length文件大小 lseek/或者使用stat查看
// prot PROT_READ | RROT_WRITE
// flags 
// MAP_SHARED: 对映射区的修改会反映到文件中（可以对文件进行修改）
// MAP_PRIVATE: 对映射区的修改不会对文件造成影响
// fd 文件的描述符
// offset 从文件的哪一个位置进行映射
// 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
int main(){
    int fd=open("../file/file.txt",O_RDWR | O_CREAT, 0775);
    if(fd==-1){
        perror("open");
        return -1;
    }

    //使用lseek求出文件大小
    int len=lseek(fd,0,SEEK_END);
    // 当然我们也可以使用stat来获取文件的属性
    struct stat st;
    stat("../file/file.txt",&st);
    printf("%ld\n",st.st_size);

    // 发现mmap是无效的参数 
    // 使用cursor智能化助手给我找问题
    // 发现file.txt是一个空文件
    void*addr=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(addr==MAP_FAILED){
        perror("mmap");
        return -1;
    }
    printf("hello i am other fork\n");
    char *p=(char *)addr;
    printf("%s\n",p);
    close(fd);
}
