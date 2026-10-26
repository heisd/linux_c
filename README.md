# Linux C 系统编程学习

记录 Linux 环境下的 C 语言与系统调用练习。每个主题目录相对独立，没有统一的全仓库构建入口。

## 主题导航

- [read](./read)、[io_function](./io_function)、[lseek](./lseek)：文件读写与偏移。
- [stat](./stat)、[lstat](./lstat)、[dir](./dir)、[opendir](./opendir)：文件信息与目录操作。
- [fork](./fork)、[exec](./exec)：进程练习。
- [pipe](./pipe)、[FIFO](./FIFO)、[mmap](./mmap)、[sign](./sign)：进程通信、内存映射与信号。
- [lib_make](./lib_make)、[lib_shared_make](./lib_shared_make)：库构建练习。

## 目录约定

各主题按需设置 `src/`（源码）、`bin/`（可执行文件）、`build/`（Makefile）、`read/`（笔记）、`include/`（头文件）与 `lib/`（库）。并非每个主题都包含这些目录。

## 编译与运行

需要 Linux 或 WSL，以及 GCC；有 Makefile 的示例还需要 Make。进入所选主题的 `src/` 后编译对应源文件，例如：

```bash
gcc source.c -o demo
./demo
```

将 `source.c` 替换为实际文件名；部分例子需要多个源文件或额外链接参数，以主题内说明为准。若主题提供 `build/Makefile`，可进入该目录执行 `make`。

这些是独立的学习代码，建议阅读源码后逐个运行。
