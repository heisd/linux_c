#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(){
	int fd = open("../file/file.txt", O_RDWR | O_CREAT, 0664);
	if(fd == -1){
		perror("open");
		return -1;
	}

	struct stat st;
	if(fstat(fd, &st) == -1){
		perror("fstat");
		close(fd);
		return -1;
	}

	size_t map_len = (size_t)st.st_size;
	if(map_len == 0){
		long page = sysconf(_SC_PAGESIZE);
		if(page <= 0) page = 4096; // fallback
		map_len = (size_t)page;
		if(ftruncate(fd, (off_t)map_len) == -1){
			perror("ftruncate");
			close(fd);
			return -1;
		}
	}

	void *addr = mmap(NULL, map_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(addr == MAP_FAILED){
		perror("mmap");
		close(fd);
		return -1;
	}

	pid_t pid = fork();
	if(pid < 0){
		perror("fork");
		munmap(addr, map_len);
		close(fd);
		return -1;
	}else if(pid == 0){
		// child: read from mapping
		sleep(1);
		char *p = (char*)addr;
		printf("child read: %s\n", p);
		munmap(addr, map_len);
		close(fd);
		_exit(0);
	}else{
		// parent: write to mapping
		const char *msg = "hello world from parent";
		size_t msg_len = strlen(msg) + 1; // include null terminator so child can printf as string
		if(msg_len > map_len) msg_len = map_len; // avoid overflow if mapping is small
		memcpy(addr, msg, msg_len);
		msync(addr, msg_len, MS_SYNC);
		wait(NULL);
		munmap(addr, map_len);
		close(fd);
	}

	return 0;
}


