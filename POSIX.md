

> ***POSIX***

从字面来说，POSIX是可移植操作系统接口（Portable Operating System Interface of Unix，POSIX）的缩写。

它是为了提高兼容性和可移植性提出来的。

它是电气与电子工程师协会（IEEE）为各种 Unix 操作系统上运行的软件而定义的一组接口。最后命名为 POSIX 的人是 Richard Stallman。

这组接口实际上是一些函数和头文件的集合。内容包括：

* 系统调用（C语言）
* shell程序
* 工具
* 线程
* 网络编程

对于多线程编程来说，被熟知为`Pthreads`。

有了这套接口，不同的类Unix操作系统就可以调用同一套API了。

想学好Linux底层接口

【参考资料】

* [A guide to POSIX](https://www.baeldung.com/linux/posix)
* [Pthread manual page](https://man7.org/linux/man-pages/man7/pthreads.7.html)
* [Online document](https://pubs.opengroup.org/onlinepubs/9699919799/nframe.html)

> ***pthread***

POSIX threads简称Pthreads。

一个进程中包含多个进程，这些进程都执行在同一个程序中。

这些线程共享一块全局内存，包括数据段和堆段（data and heap segment）。但每个线程有自己独立的栈（自动变量）。



> 库函数



> 系统调用