# 模块索引

## IPC 与进程通信
- `FIFO`: 命名管道示例（`fifoa.c`, `fifob.c`）
- `pipe`: 匿名管道、阻塞/非阻塞、组合命令示例

## 进程控制
- `fork`: 进程创建、孤儿进程、僵尸进程、`wait/waitpid`
- `exec`: `execl/execlp` 调用示例

## 信号
- `sign`: `signal` 与 `kill` 示例

## 文件与目录
- `read`: 阻塞与非阻塞读取示例
- `lseek`: 文件偏移与文件扩展示例
- `stat`: 文件属性读取
- `lstat`: 软链接属性读取
- `fcntl`: 文件描述符复制与标志位
- `dup`: `dup/dup2` 示例
- `perror`: 系统错误输出
- `cwd`: 当前工作目录
- `dir`: 目录遍历
- `opendir`: 递归目录统计

## 内存映射
- `mmap`: `mmap` 基础与匿名映射

## 构建与库
- `calculator`: 多文件计算器示例
- `lib_make`: 静态库构建与链接
- `lib_shared_make`: 共享库构建与运行

## 其他
- `io_function`: 基础 IO 串联示例
- `test`: 单文件测试示例
