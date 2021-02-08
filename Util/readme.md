# 编译共享模块

```shell
gcc -std=gnu11 -O1 -I./ -shared -fpic -o fmy-util.so fmy-io-ext/*.c fmy-string/*.c
```

# 编译测试程序

```shell
gcc -std=gnu11 -O1 -I./ test.c /home/fmy/C/Util/fmy-util.so
```

# 测试

```shell
./a.out
```