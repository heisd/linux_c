#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/dir.h>
#include <dirent.h>
#include <sys/stat.h>
int checkdir(char*path);
int main(){
    char cwd[1024];
    if(getcwd(cwd,sizeof(cwd))!=NULL){
        printf("cwd is %s\n",cwd);
    }
    int n=0;
    n=checkdir("/home/li/桌面/c");
    printf("n=%d\n",n);
    return 0;
}
int checkdir(char *path){
    DIR*pdir=opendir(path);
    if(pdir==NULL){
        perror("opendir");
        return -1;
    int n=0;
    char sfullpath[1024];
    struct dirent* p=readdir(pdir);
    while (p!=NULL)
    {
        if(strcmp(p->d_name,".")||strcmp(p->d_name,"..")){
            continue;
        }
        printf("file name :%s/%s",path,p->d_name);
        switch (p->d_type)
        {
        case DT_REG:
            printf("this is regular file");
            n++;
            break;
        case DT_DIR:
            printf("this is a dir");
            memset(sfullpath,0x00,sizeof(sfullpath));
            sprintf(sfullpath,"%s/%s",path,p->d_name);
            n+=checkdir(sfullpath);
            break;
        case DT_LNK:
            printf("link file");
            n++;
            break;
        default:
            break;
        }
    }
}
}
