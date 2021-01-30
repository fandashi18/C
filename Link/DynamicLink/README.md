# 创建共享目标

```
gcc -std=c99 -Og -shared -fpic -o libmath.so add.c
```

# 程序加载后执行前进行动态链接

```
gcc -std=c99 -Og -o main main.c ./libmath.so -ldl
```
若不引用dlfcn.h中定义的符号，则不必加入参数 `-ldl`.
 

# 程序运行时进行动态链接

## 引用共享目标中的符号

```c
    static void * handle;
    static int (* add)(int,int);
    handle = dlopen("./libmath.so",RTLD_LAZY);
    if (!handle)
    {
        printf("error ：%s\n", dlerror());
        exit(1);
    }
    
    add = dlsym(handle,"add");
    if (!add)
    {
        printf("error ：%s\n", dlerror());
        exit(1);
    }

    int result = add(1,2);
```

## 创建可执行目标文件

```
gcc -std=c99 -Og -rdynamic -o main main.c -ldl
```

## 加载并运行可执行目标模块

```
./main
```

# 其他

Java中的JNI原理即是如此。
