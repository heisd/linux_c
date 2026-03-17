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
int checkdir(const char *path);
int main(int argc, char *argv[]){
    char cwd[1024];
    if(getcwd(cwd,sizeof(cwd))!=NULL){
        printf("cwd is %s\n",cwd);
    }
    int n=0;
    const char *target = (argc > 1) ? argv[1] : ".";
    n=checkdir(target);
    printf("n=%d\n",n);
    return 0;
}
int checkdir(const char *path){
    DIR*pdir=opendir(path);
    if(pdir==NULL){
        perror("opendir");
        return -1;
    }
    int n=0;
    char sfullpath[1024];
    struct dirent* p=readdir(pdir);
    while (p!=NULL) {
        if(strcmp(p->d_name,".")==0 || strcmp(p->d_name,"..")==0){
            p = readdir(pdir);
            continue;
        }
        printf("file name :%s/%s\n",path,p->d_name);
        switch (p->d_type) {
        case DT_REG:
            printf("this is regular file\n");
            n++;
            break;
        case DT_DIR:
            printf("this is a dir\n");
            memset(sfullpath,0x00,sizeof(sfullpath));
            sprintf(sfullpath,"%s/%s",path,p->d_name);
            n+=checkdir(sfullpath);
            break;
        case DT_LNK:
            printf("link file\n");
            n++;
            break;
        default:
            break;
        }
        p = readdir(pdir);
    }
    closedir(pdir);
    return n;
}
