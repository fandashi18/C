# 编译过程

可以直接使用命令
```
make all
```
也可以按照以下过程执行。

## 创建out目录

```
mkdir out
cd out
```

## 编译可重定位目标文件

```
gcc -std=c99 -O0 -c ./../*/*.c
```

## 编译可执行文件

各个目标模块之间无依赖关系，故顺序任意。

```
cd ../
gcc -std=c99 -O0 -o main main.c ./out/*.o
```