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

- [x] 地址空间
- [x] 虚拟内存
- [x] 虚拟页
- [x] 物理页
- [x] 页表
- [x] 页命中
- [x] 缺页

​	

> ***地址空间***

虚拟地址空间（ Virtual Address Space，简称**VAS**）的大小是由表示最大地址所需位数来描述的，例如一个包含**N=2^n^**个地址的vas，就叫一个 **n** 位虚拟地址空间。现代操作系统通常支持 **32** 位或 **64** 位虚拟地址空间。

物理地址空间（Physical Addres Space，简称**PAS**）对应的是物理内存中的字节数。假设内存有 **M** 个字节，不要求M是2的幂，为了简化讨论，假定 **M=2^m^**，代表一个 **m** 位物理地址空间。

> ***虚拟内存***

虚拟内存系统（**Virtual Memory**，**VM**）被组织为一个存放在磁盘上的 **N** 个连续字节单元组成的数组。

* 一个连续数组
* 数组元素是字节单元
* 存放在磁盘上

每个字节有一个唯一的虚拟地址作为数组索引。

磁盘上数组的内容被缓存在内存中。

> ***虚拟页与物理页***

磁盘上的数据被分割成块，将这些块作为磁盘和内存间的数据传输单元。VM 系统将这些固定大小的块称为**虚拟页**（**Virtual Page，VP**），每个虚拟页大小为 **P=2^p^** 个字节。（通常VP大小为4KB~2MB）

物理内存也被分割为同样大小的块，每个块也是 **P** 字节，这些块称为**物理页**（**Physical Page，PP**），物理页也被称为**页帧**（**Page Frame**）。

虚拟页可以分为三个互斥子集：

1. **未分配**

    未分配的VP无任何数据与其关联（可以理解为其中无数据），故不占用任何磁盘空间。

2. **已缓存**

    已缓存在内存中的已分配页。

3. **未缓存**

    为缓存在内存中的已分配页。

> ***页表***

**VM** 需要知道一个 **VP** 是否已缓存到内存中。若已缓存，还需要知道这个 **VP** 放在哪个 **PP** 中。若不命中，还需要知道这个 **VP** 存放在磁盘的位置，同时在内存中选择一个牺牲页，并将 **VP** 从磁盘中复制到内存中，替换该牺牲页。想要实现以上功能需要以下几个软硬件联合提供：

1. OS
2. MMU
3. 页表

**页表**（**Page Table，PT**）将 **VP** 映射到 **PP** ，每次 **MMU** 需要将 **VA** 转为 **PA** 时，都会先读取页表。**OS** 负责维护页表内容以及在磁盘与内存简传送页。**页表常驻内存**。

作为数据结构，页表可以理解为**页表条目**（**Page Table Entry，PTE**）的数组。

虚拟地址空间中的每一个 **VP** 都在 **PT** 中有对应的一个 **PTE**，每个 **PTE** 的结构如下：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/11.png" style="zoom: 80%;" />

**有效位**表明该虚拟页是否被缓存在内存中。若置为 1 ，那么随后的地址字段内容是内存中的物理页（缓存了该虚拟页）对应的起始地址。若置为 0 ，就有两种情况，一种是未分配的虚拟页，另一种是已分配但未缓存的虚拟页。前一种地址字段为空地址，后一种地址字段的内容是该虚拟页在磁盘中的起始位置。页表工作机制示意图如下：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230207193934852.png" alt="image-20230207193934852" style="zoom: 33%;" />

此时存在 VP0 与 VP5 未分配，所以对应的 **PTE** 地址字段是 **null**（空地址）。VP3 与 VP6 已分配但未缓存，地址字段是虚拟页在磁盘中的起始地址。剩余的 VP（1、2、4、7）都已缓存，它们对应的 PTE 地址字段都是物理内存中PP的起始地址。

> ***页命中***

如果 CPU 想读取上图 VP2 中的一个数据字时，MMU 将虚拟地址作为索引来找到 PTE2 ，并从内存中读取它，然后得知在内存中的物理地址（PP1的起始地址），从而构造出这个数据字的物理地址。

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230207195807468.png" alt="image-20230207195807468" style="zoom:33%;" />

> ***缺页***

内存缓存**不命中**称为**缺页**（**Page Fault**）。考虑如下情况：CPU 引用 VP3 中的一个数据字，但是 MMU 从 PTE3 中发现有效位为0，推断出 VP3 并未被缓存，随即触发一个**缺页异常**。

缺页异常会调用内核中的**缺页异常处理程序**。该程序会选择一个物理页作为**牺牲页**，例如选择存放在 PP3 中的 VP4，内核将其复制回磁盘。然后内核会修改 PTE4 的有效位为0，反映出 VP4 不再缓存与内存中。

接下来，内核从磁盘复制 VP3 到 PP3 中，并更新 PTE3 的有效位，随后返回缺页异常处。

最后重启导致缺页的指令，该指令会把导致缺页的虚拟地址重新发送给 MMU，之后会页命中。修改完如下图：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230207201040611.png" alt="image-20230207201040611" style="zoom:33%;" />



# 0213

- [x] 虚拟地址
- [x] 物理地址
- [ ] 地址翻译



> ***虚拟地址***

n 位虚拟地址（**VA**）由两部分组成，一部分是虚拟页号（**Virtual Page Number，VPN**），另一部分是虚拟页偏移量（**Virtual Page Offset，VPO**）。设 VPO 位数为 p ，则 VPN 位数为 n-p 位，一个 VA 的组成示意图如下：

![](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/VA1.png)

> ***物理地址***

m 位物理地址（**PA**）由两部分组成，一部分是物理页号（**Physical Page Number，PPN**），另一部分是物理页偏移量（**Physical Page Offset，PPO**）。设 PPO 位数为 p ，则 PPN 位数为 n-p 位，一个 PA 的组成示意图如下：

![](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/PA.png)