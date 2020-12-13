# ECF

全称Exception Control Flow，异常控制流。指的是控制流发生的突变，是计算机系统实现进程，虚拟内存，IO与并发的基本机制。

## 形成原因

计算机系统为了对系统状态的变化作出响应。

这些变化可能是磁盘请求或网络数据包到达或子进程终止等。

## 异常

控制流发生突变的情况有很多种，异常属于其中的一种。

异常一部分由硬件实现，一部分由软件实现。因此，不同计算机的异常很可能是不同的。

操作系统在开机时，会在内核的地址空间中存放一张异常表。表中每一条记录都是一种异常的处理程序的虚拟地址。这些不同种类的异常由非负的异常号唯一标识。其中，0～31号是由CPU架构师定义的，32～255是由操作系统的内核设计者定义的。

发生异常时，可能是同步的，也可能是异步的。该异常可能是可处理的，也可能是不可处理的。对于不可处理的情况，内核会直接终止发生异常的进程，随后该进程会被init进程收养，从而其资源被init进程wait而得到释放。

### 分类




## 进程

从表面上看，进程就是一个运行中的程序。这里的关键是`运行`，程序本身只是一段代码和数据，不论其是位于磁盘还是主存。

实际上，进程是逻辑流的一种形式。实质是一个指令地址序列。逻辑流的实例还有异常处理程序等。

逻辑流是逻辑控制的序列。

而逻辑控制是PC寄存器中指令的过渡过程。

### 并发流

当一个逻辑流与另一个流在执行时间上发生重叠，则称这两个流为并发（逻辑）流。

这里所说的重叠与处理器核心数无关。不过，若多个逻辑流在不同的处理器核心上发生并发，则称此现象为并行。因此，可以说并行是并发的一个真子集。
