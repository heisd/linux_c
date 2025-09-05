#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// for open, read, write, close
#include <sys/types.h>
// for lseek
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[]){
    //
    char cwd[1024];
    if(getcwd(cwd, sizeof(cwd)) != NULL){
        printf("Current working dir: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }
    
    int file = open("./file/file.txt", O_RDWR | O_CREAT, 0777);
    // check if file descriptor is valid
    if(file == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    const char *str = "Hello, World!\n";
    // write string to file
    write(file, str, strlen(str));
    // move file offset to the beginning
    lseek(file, 0, SEEK_SET);
    // read string from file
    // buffer to store read string
    char buf[100];
    memset(buf, 0, sizeof(buf));
    read(file, buf, sizeof(buf));
    // print string to stdout
    printf("%s", buf);
    // close file descriptor
    close(file);
    return 0;
}
