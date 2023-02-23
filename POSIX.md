

> ***POSIX***



POSIX从实体上来说，是一个接口的集合。这个集合中包括一些函数和头文件。对于多线程编程来说，被熟知为`Pthreads`。

一些重要的POSIX标准。



【参考资料】

* [A guide to POSIX](https://www.baeldung.com/linux/posix)
* [Pthread manual page](https://man7.org/linux/man-pages/man7/pthreads.7.html)

> ***pthread***

POSIX threads简称Pthreads。

一个进程中包含多个进程，这些进程都执行在同一个程序中。

这些线程共享一块全局内存，包括数据段和堆段（data and heap segment）。但每个线程有自己独立的栈（自动变量）。