# 一、管道

【**特点**】

1. 亲缘关系
2. 半双工
3. 文件IO（不支持lseek函数）

【**本质**】

* 内核缓冲区：在内核内存空间中是一个缓冲区
*  两个文件描述符就是缓冲区的两端

【**异常**】

* 读阻塞：无数据
* 写阻塞：已写满
* 管道破裂：读端关闭，继续写数据

【读写端】

* `fd[0]`：读端
* `fd[1]`：写端



单个进程（父进程）创建管道，得到两个文件描述符：`fd[0]`、`fd[1]`

图一

但是单个进程的管道是不存在通信的，父进程调用创建子进程，此时子进程也有两个文件描述符指向同一个管道。

图二

分为两种情况：

1. 数据流向为从父进程到子进程

    父进程关闭读端（`close(fd[0])`），子进程关闭写端（`close(fd[1])`），这样父进程可以往管道里写数据，子进程可以从管道里读数据。

    图三

2. 数据流向为从子进程到父进程

    父进程关闭写端（`close(fd[1])`），子进程关闭读端（`close(fd[0])`），这样子进程可以往管道里写数据，父进程可以从管道里读数据。

    图四



# 二、使用管道

一般在创建子进程前由父进程调用`pipe()`系统调用，这样两个进程才能共享管道的读写端两个 fd，然后利用`fork()`系统调用创建子进程。

子进程会继承父进程打开的文件句柄，所以父子进程可以通过创建的管道进行通信。

```c
#include<stdio.h>
#incldude<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    /* 0.准备用于传输的数据 */
    char *msg = "This is pipe test.";
    char buf[512];  //开辟缓冲区
    
    /* 1.创建管道 */
    int fd[2];            //用于管道读写端的两个文件描述符
    int ret = -1;
    ret = pipe(fd);
    if(ret == -1){       //判断管道是否创建成功
        printf("Failed to create pipe!\n");
        return -1；
    }
    /* 2.创建子进程 */
    pid_t pid;
    pid = fork();
    if(pid < 0 )
        printf("Failed to fork!\n");
    else if(pid == 0){         //子进程
        close(fd[0]);          //关闭读端
        ret = write(fd[1],msg,strlen(msg));  //子进程向管道写端写数据
        exit(0);
    }
    else{                 //父进程
        close(fd[1]);     //关闭管道写端
        ret = read(fd[0], buf, sizeof(buf)); //父进程从管道读端读取数据
        printf("Parent read %d bytes data: %s\n",ret,buf);
    }
    return 0;
}
```

> 利用`fork()`创建进程时，返回值为`0`为子进程，返回值为负，则说明是



# 三、fork()

【**头文件**】

```c
#include<unistd.h>
#include<sys/types.h>
```

【**返回值**】

若调用成功，返回两个值，子进程中返回 0 ，父进程中返回子进程 pid，调用出错返回 -1 。

【**子进程**】

子进程与父进程只共享代码段，其他资源子（数据段、堆、栈等）进程获得父进程的副本。





# 四、Linux 内核实现





# 参考资料

1. [图解 Linux 管道](https://cloud.tencent.com/developer/article/1890707)
2. [Linux 管道](http://www.tlcement.com/36291.html)
3. [一文弄懂 Linux 进程间通信](https://zhuanlan.zhihu.com/p/461486127)
4. [Linux 系统编程之管道](https://cloud.tencent.com/developer/article/1007497)
5. [进程间五种通信方式](https://learnku.com/articles/44477)
6. [管道读写端关闭问题](https://www.cnblogs.com/whiteHome/p/4863516.html)

