# 创建共享目标

```
gcc -shared -fpic -std=c99 -Og -o libmath.so add.c
```

# 引用共享目标中的符号

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

# 创建可执行目标文件

```
gcc -std=c99 -rdynamic -o main main.c -ldl
```

# 加载并运行可执行目标模块

```
./main
```

# 其他

Java中的JNI原理即是如此。
