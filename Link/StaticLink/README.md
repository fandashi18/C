# 创建可重定位目标文件

```
gcc -std=c99 -Og -c add.c sub.c
```

# 创建静态库

```
ar -sr ./lib/libmath.a add.o sub.o
```

# 引用静态库

```c
#include "math.h"

int main(int argc, char const *argv[])
{
    static int result;
    result = add(1,2);
    printf("Add result is %d\n",result);

    result = sub(1,2);
    printf("Sub result is %d\n",result);
    
    return 0;
}
```

# 创建可执行目标文件

```
gcc -std=c99 -Og -o main main.c ./lib/libmath.a
```
OR
```
gcc -std=c99 -Og -o main main.c -L./lib -lmath
```

# 加载并运行可执行目标模块

```
./main
```
