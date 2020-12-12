# fork

+ 调用1次返回2次
+ 父子进程拥有相同但独立的地址空间
+ 相同的文件描述符
+ 父子进程并发执行

# 编译命令

```
gcc -std=c99 -O0 main.c -o main
```

# 输出

```
child process pid is 8009
parent process x = 2
child process x = 0
```
