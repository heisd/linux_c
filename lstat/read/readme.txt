using stat | lstat funtction to get file 
funtction 
int stat(cosnt char*pathname,struct stat *buf)
int lstat(cosnt char*pathname,struct stat *buf)
function return 
is success return 0
is faith return -1

stat funtction
st_mode : 
0~2 other people write | read | execute
S_IROTH 00004 read
S_IWOTH 00002 write
S_IXOTH 00001 execute
S_IRWXO 00007 mask
3~5 user in group write | read | execute
S_IRGRP 00040 read
S_IWGRP 00020 write
S_IXGRP 00010 execute
S_IRWXG 00070 mask
6-8 file user write | read | execute
S_IRUSR 00400 read
S_IWUSR 00200 write
S_IXUSR 00100 execute
S_IRWXU 00700 mask
12-15 file style
__S_IFSOCK 0140000   socket
__S_IFLNK  0120000   soft link
__S_IFREG  0100000   common file
__S_IFBLK  0060000   block device
__S_IFDIR  0040000   dir
__S_IFCHR  0002000   char
__s_IFIFO  0001000   pipeline
         0170000   mask







