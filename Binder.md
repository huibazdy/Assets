

> 学习Binder并将其与传统IPC方式对比，有助于深入理解IPC实现与优化。



# Binder引入

## 传输性能

常见的进程间通信（IPC）方式有：socket、管道、System V IPC（消息队列、共享内存、信号量）等。在安卓IPC场景下，都有各自的局限性。

* **socket**

    通用接口，传输效率低，开销大。主要用于跨网络IPC以及本机低速IPC。

* **消息队列与管道**

    这两种采用存储转发方式，即：将数据从发送方缓冲区拷贝至内核开辟的缓冲区中，然后再将数据从内核缓冲区拷贝至接收方缓冲区。至少存在两次拷贝。

* **共享内存**

    无需数据拷贝，但控制复杂，难以使用。



## 安全性

传统IPC方式本身没有任何安全措施，完全依赖上层协议来确保安全性。Android应用程序来源广泛，需要防范下载的程序在用户不知情的情况下窃取隐私数据、连接无线网、操作底层设备导致功耗高等情况。

首先，传统IPC无法鉴别对方身份，即进程的UID或PID。原因是传统IPC只能由用户在数据包中填入UID或PID。这样做的结果是，容易被恶意程序利用。

可靠的身份标记只能由IPC机制本身在内核中添加。

其次，传统IPC访问接入点是开放的，无法建立私有通道。如命名管道的名称、system V的键值、socket的IP地址以及文件名。只要知道这些接入点的信息，都可以和对端建立连接。因此无论怎样都无法阻止恶意程序建立链接。

因此，基于对传输性能和安全性的考虑，Android提出了一种新的IPC方式，就是Binder。



# Binder通信模型

Binder作为安卓主要的IPC方式。

回想一下传统的C/S架构，Client端需要给出Server端的IP地址以及端口号才能实现访问，同理实现一个Binder为了实现C/S架构也需要一个类似于IP地址能够找到Server的入口，或者说找到Server的**接入点**。

找到了通信对象之后，类似于计网中的概念，很自然的需要一个**通信协议**来实现数据传输，类似于TCP/IP协议族。

对于Binder本身来说，可以将其看做是某个特定服务的访问接入点（IP+端口号）。Client通过这个Binder接入点来向Server发送请求，并使用Server的相关服务。

对Client而言，Binder是一个通向特定Server的管道，要想和Server通信，必须先建立这个管道，并获得管道入口。

面向对象思想将IPC转化为对某个Binder对象的引用来调用该对象的方法，其特点是Binder对象是一个可以跨进程引用的对象，它的实体位于一个进程中，而它的引用位于各个进程中。而且这个引用可以从一个进程传给另一个进程。让大家都能访问一个server。

Binder驱动在内核中为面向对象的这种IPC方式提供底层支持。



## 四大组件

Binder采用的C/S架构可以大致划分为四大组件：

* **Client**

* **Server**

* **ServiceManager**

    ServiceManager是Binder的守护进程，充当大管家的角色。要掌握Binder机制，首先需要了解ServiceManger的启动机制，即系统是如何首次启动ServiceManager的。当Service Manager启动后，client与server通信时才能获取Service Manager的接口进行通信。

* **Binder驱动**

粗略的Binder架构如下图：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/2.png" style="zoom: 50%;" />

【注意】

此处的ServiceManger位于native framwork层（C++）。

虚线说明Client与Server不是直接交互的，只代表逻辑上的交互，实际交互是通过Binder驱动来实现的。

除了Binder驱动位于内核空间，其他三个组件位于用户空间。



## 运行流程

Binder详细的运行流程图如下：



<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/binder.png"  />

## 代码解读

从上至下涉及到Binder 的代码路径：

![](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/3.png)

* **Java Frameworks & JNI**

![](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/4.png)

* **Native Framework**

![](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/5.png)

* **Driver(Kernel)**

![](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/6.png)



# Binder通信协议

## Binder实体





## Binder引用



# 参考资料

1. [Binder设计篇](https://blog.csdn.net/universus/article/details/6211589)