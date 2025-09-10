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
int main(){
    printf("hello dir\n");
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }
    // this is it what is about dir
    // open dir
    // function
    //DIR* opendir(const char *name)
    DIR*pdir=opendir("../src/dir");
    if(pdir==NULL){
        perror("opendir");
        return 0;
    }
    // read dir
    // readdir function read dir file
    // if it reutrn NULL it is read over
    // function
    // dirent * readdir(DIR*dirp)
    // read in dir file
    // dirent struct
    // struct dirent{
    //     ino_t d_ino;
    //     off_t d_off;
    //     signed short int d_reclen;
    //     unsigned char d_type;
    //     char d_name[256];
    // }
    struct dirent *p;
    while((p=readdir(pdir))!=NULL){
        // filter . and ..
        // strcmp return 0 is same
        if(strcmp(p->d_name,".")==0 || strcmp(p->d_name,"..")==0){
            continue;
        }
        printf("file name:%s\n",p->d_name);
        // file type
        switch (p->d_type)
        {
        case DT_REG:
            printf("file type: regular file\n");
            break;
        case DT_DIR:
            printf("file type: directory\n");
            break;
        case DT_LNK:
            printf("file type: symbolic link\n");
            break;
        default:
            printf("file type: unknown\n");
            break;
        }
    }
    // close dir
    closedir(pdir);
    return 0;
}