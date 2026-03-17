#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(void){
    struct stat st;
    if(stat("file/dir",&st)==-1){
        perror("stat");
        return 0;
    }
    // this is using to get file type
    // #define __S_IFMT  0170000 /* type of file */
    // #define __S_IFDIR  0040000 /* directory */
    // #define __S_IFCHR  0002000 /* character special */
    // #define __S_IFBLK  0060000 /* block special */
    // #define __S_IFREG  0100000 /* regular */
    // #define __S_IFIFO  0001000 /* fifo special */
    // #define __S_IFLNK  0120000 /* symbolic link */
    // #define __S_IFSOCK 0140000 /* socket */
    // using stat only ponit file style if it is soft link
    if(S_ISREG(st.st_mode)){
        printf("user have common file\n");
    }
    else if(S_ISDIR(st.st_mode)){
        printf("user have dir file\n");
    }
    else if(S_ISLNK(st.st_mode)){
        printf("user have soft link file\n");
    }
    else{
        printf("user have other file\n");
    }
    return 0;
}
