# 0206

- [ ] ==函数指针==
- [ ] ==回调函数==



> ***什么是函数指针？***

类似于变量，函数也是有自己的地址的。所谓函数的地址，就是函数代码的起始处的地址。而函数指针中存储的就是函数代码的起始地址。

函数指针的声明必须指明函数的类型，这就包括函数签名（返回类型、形参类型），例如一个函数原型为：

`void toUpper(char *);     //函数原型`

声明一个指向该函数的指针`pFunc`：

`void (*pFunc)(char *);   //声明函数指针`

可以看出：**将函数名替换为指针表达式**是创建函数指针最简单的方式，注意此处**必须使用小括号**。所以，如果想声明一个指向某函数的指针，只需先写出该函数的原型，然后用指针表达式替换函数名即可。

声明了函数指针后，需要将该函数的地址传递给该指针，方法就是用**函数名充当地址**值赋给指针：

`pFunc = toUpper;        //赋予函数地址`     



> ***如何使用函数指针？***

就像数据指针可以访问数据，函数指针也可以直接访问函数。给出实参：`char name[] = "Eric";`通过函数指针来调用函数的写法：

1. `(*pFunc)(name);  //等同于：toUpper(name);`
2. `pFunc(name);    //等同于：toUpper(name);`

函数指针最常见的用法是作为函数的参数：

```c
void show(void (*pFunc)(char *) ,char * str);
```

以上函数声明了两个参数，一个是函数指针pFunc，另一个是数据指针str。如果存在以上声明，你可以这样调用函数show：

1. `show(toUpper,name);`
2. `show(pFunc,name);`



把带返回值的函数作为参数传递给另一个函数有两种不同使用方法：

1. `func1(sqrt);    //传递函数地址`
2. `func2(sqrt(4.0));    //传递函数返回值`



> ***什么是回调函数？***

回调函数是一种使用函数的机制。它可以使某个函数（简记为函数`F1`）像传递参数那样传递给另一个函数（简记为函数`F2`）。

该机制的实现基础是**函数指针**。

回调：说明`F1`不是由该函数的实现方直接调用，而是对某种事件的响应，需要由`F2`而间接调用`F1`。

使用回调函数（带参数的情况）的例子：

```c
#include<stdio.h>

int Callback1(int a){
    printf("This is Callback 1,answer is: %d\n",a);
}
int Callback2(int b){
    printf("This is Callback 1,answer is: %d\n",2 * b);
}

int Handle(int x, int (*pf)(int)){
    pf(x);
}

int main()
{
    Handle(1,Callback1);
    Handle(2,Callback2);
    return 0;
}
```



> ***为什么要使用回调函数？***

解耦。可以从下图中理解：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/9.png" style="zoom:50%;" />

看似不过是函数的简介调用，但可以通过改变传进库函数的实参（Callback1、Callback2...）而不需要修改库函数的实现方式来实现不同的功能或者说更丰富的功能。

另一方面，主函数与回调函数可能都在用户空间，而库函数可能在内核空间，对于用户不可见，更无法修改库函数的实现，而只能通过传入不同的回调函数来实现对库函数功能上的改变。



参考资料：

1. [C语言函数指针与回调函数](https://ost.51cto.com/posts/1114?u_atoken=fb7e9c7f-044f-4e2d-a47c-389b3a45ce95&u_asession=01zcmGlV2OXosyqiPY0MxyvfKAKO66jlTqMkdXl_ejKzds5ZLU0ld7b_MhV5GFhPZXX0KNBwm7Lovlpxjd_P_q4JsKWYrT3W_NKPr8w6oU7K8rYSYteNOjpcX2B87uPaRRq7xudZJwxaIsiPXb3YolxmBkFo3NEHBv0PZUm6pbxQU&u_asig=059Az3Xd5we7lcAslF8C0b3dAExydwLAmSBaAobUtRpv1zvHpM57Q3hBdaOh1Ive2PF4XvsJdfwLAE2nw7qr11BPtTTeGmODY3Uhs-f2ohObYefH2lz7RKbA471tFV7jhMCczfcVw2WShXJmLHZUVehyPyKppFNyyot7dvxA-msmz9JS7q8ZD7Xtz2Ly-b0kmuyAKRFSVJkkdwVUnyHAIJzea7BqLegvk-YAhvhb2K_lo8h0NUmOuJ3tEeOQsEUJ3j2Rvl9B2xFpjpl-FzTJYuz-3h9VXwMyh6PgyDIVSG1W_sWQzkH9JDQ4bA3FqmtYbXD9O7Kg2rpaCHh2dXFv--8yT6WzyW1IbYDNoYxJ5e0KGQlOAwlow_T8UqpGlItT7WmWspDxyAEEo4kbsryBKb9Q&u_aref=TyBPO%2BZQUID6K1SFDLL0CVbK1Ic%3D)
2. [C语言回调函数详解](https://www.runoob.com/w3cnote/c-callback-function.html)

---



# 0207

- [ ] 物理寻址（PA）
- [ ] 虚拟寻址（VA）
- [ ] 内存管理单元（MMU）
- [ ] 内存查询表
- [ ] 地址空间

​	

> ***地址空间***

虚拟地址空间（ virtual address space，简称**vas**）的大小是由表示最大地址所需位数来描述的，例如一个包含**N=2^n^**个地址的vad，就叫一个n位虚拟地址空间。现代操作系统通常支持 **32** 位或 **64** 位虚拟地址空间。

物理地址空间（physical addres space，简称**pas**）对应的是物理内存中的字节数。假设内存有 **M** 个字节，不要求M是2的幂，为了简化讨论，假定 **M=2^m^**。

> ***虚拟内存***

虚拟内存（**Virtual Memory**，**VM**）被组织为一个存放在磁盘上的N个连续字节大小的单元组成的数组。

* 一个连续数组
* 数组元素是字节单元
* 存放在磁盘上

每个字节有一个唯一的虚拟地址作为数组索引。

磁盘上数组的内容被缓存在内存中。



> ***虚拟页与物理页***

磁盘上的数据被分割成块，将这些块作为磁盘和内存间的数据传输单元。VM系统将这些固定大小的块称为**虚拟页**（**Virtual Page，VP**），每个虚拟页大小为 **P=2^p^** 个字节。（通常VP大小为4KB~2MB）

物理内存也被分割为同样大小的块，每个块也是 **P** 字节，这些块称为**物理页**（**Physical Page，PP**），物理页也被称为**页帧**（**Page Frame**）。



虚拟页可以分为三个互斥子集：

1. **未分配**

    未分配的VP无任何数据与其关联（可以理解为其中无数据），故不占用任何磁盘空间。

2. **已缓存**

    已缓存在内存中的已分配页。

3. **未缓存**

    为缓存在内存中的已分配页。



> ***命中与缺页***

* 页命中
* 缺页
* 牺牲页



> ***页表***

VM需要知道一个VP是否已缓存到内存中。若已缓存，还需要知道这个VP放在哪个PP中。若不命中，还需要知道这个VP存放在磁盘的位置，同时在内存中选择一个牺牲页，并将VP从磁盘中复制到内存中，替换该牺牲页。

想要实现以上功能需要以下几个软硬件联合提供：

1. OS
2. MMU中的地址译码器
3. 内存中的一个叫页表的数据结构

**页表**（**Page Table，PT**）将 VP 映射到 PP ，每次地址翻译硬件将 VA 转为 PA 时，都会读取页表。OS 负责维护页表内容以及在磁盘与内存简传送页。