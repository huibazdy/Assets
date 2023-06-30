# Hello GDB



## 编译选项

`-O0`

构建可执行目标文件，并**禁用编译器优化**（编译器有四个优化级别：O1~O4），关闭优化是为了调试时符号文件的调试变量能与源代码完全对应起来。不关闭编译器优化会给排查和定位问题带来困难。

`-g`

在编译出来的目标文件中加上**调试信息**

`-g3`

告诉编译器打印包括**宏在内的调试信息**

> 小结：使用`-O0 -g3`来编译源代码



最终编译命令应该为以下形式：

```shell
gcc -O0 -g3 -o <ELF_name> hello.c
```



## 启动 GDB

`gdb <ELF_file_name>`

> 对某个源文件进入GDB调试模式

`gdb -q <ELF_file_name>`

> 进入GDB调试模式，但不显示欢迎语，`q`代表quiet



对加了调试信息的ELF文件启动gdb后会有一行提示符：

![image-20230630151547817](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230630151547817.png)

它的意思是从编译得到的目标文件中读取**符号文件**（**symbols**）完毕。



如果没有加调试信息的ELF文件启动提示：

![image-20230630152434309](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230630152434309.png)

依然是读取了符号文件，但是没有读取到任何调试符号文件。



对于大型程序，为了避免重复编译，可以利用`strip`指令去掉ELF文件中已经带有的调试信息

![image-20230630152856611](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230630152856611.png)

另一方面，在调试结束后需要发布，也要减小程序大小，也需要去掉调试信息。







## 传递参数

最常用的有两种传递参数的方式，一种是 `run` 命令，另一种是启动时使用 `--args` 命令。





## 参考资料

1. [Get Started with our GNU Debugger Tutorial](https://developers.redhat.com/blog/2021/04/30/the-gdb-developers-gnu-debugger-tutorial-part-1-getting-started-with-the-debugger)