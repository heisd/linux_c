# Linux C 系统编程练习仓库

这个仓库整理了 Linux C 开发中的常见系统调用与编程主题。每个主题拆成独立目录，便于单独编译和调试。

## 快速开始

### 1) 构建全部模块

```bash
make all
```

### 2) 查看模块列表

```bash
make list
```

### 3) 运行某个模块

```bash
make -C pipe run
make -C fork run
```

### 4) 清理构建产物

```bash
make clean
```

## 目录说明

统一约定（多数模块）：
- `src/`: 源码
- `bin/`: 可执行文件输出目录
- `build/`: 中间构建目录（如目标文件）
- `include/`: 头文件
- `lib/`: 静态/共享库产物
- `read/` 或 `reference/`: 参考资料

详细模块索引见 [docs/MODULES.md](docs/MODULES.md)。

## 模块主题

- 进程与执行：`fork`、`exec`
- 信号：`sign`
- 文件与文件描述符：`read`、`lseek`、`stat`、`lstat`、`fcntl`、`dup`、`perror`
- 目录：`cwd`、`dir`、`opendir`
- IPC：`pipe`、`FIFO`
- 内存映射：`mmap`
- 构建与库：`calculator`、`lib_make`、`lib_shared_make`

## 本次重构要点

- 新增顶层 `Makefile`，支持统一构建/运行/清理。
- 为各模块补齐 `Makefile`（`make / make run / make clean`）。
- 目录命名规范化：`calcuator` -> `calculator`。
- 文件命名修正：
  - `fork/src/orphana_process.c` -> `fork/src/orphan_process.c`
  - `mmap/src/mmap_anonyous.c` -> `mmap/src/mmap_anonymous.c`
- 修复可移植性与示例问题：
  - `exec/src/execl.c` 去除本机绝对路径
  - `opendir/src/opendir.c` 去除硬编码目录并修复遍历逻辑
  - `pipe/src/pipe_practice2.c` 修复 `execlp` 参数

## 注意

部分示例会依赖 Linux 环境行为（如 `/dev/tty`、signal、pipe 阻塞语义）。建议在 Linux 或 WSL 环境下验证运行效果。
