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
    int len =lseek(fd,0,SEEK_END);
    void *addr=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(addr==MAP_FAILED){
        perror("mmap");
        return -1;
    }
    memcpy(addr,"hello other fork\n",sizeof("hello other fork")); 
    // 保证进程在我们使用之前没有结束生命
    getchar();
}
