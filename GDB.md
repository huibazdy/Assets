# Hello GDB



## 编译选项

`-O0`

构建可执行文件，关闭编译器优化

`-g`

打印调试信息

`-g3`

告诉编译器打印包括宏在内的调试信息

> 小结：使用`-o0 -g3`来编译源代码





## 启动 GDB

`gdb <program_file_name>`

对某个源文件进入GDB调试模式

`gdb -q <program_file_name>`

进入GDB调试模式，但不显示欢迎语



## 传递参数

最常用的有两种传递参数的方式，一种是 `run` 命令，另一种是启动时使用 `--args` 命令。





## 参考资料

1. [Get Started with our GNU Debugger Tutorial](https://developers.redhat.com/blog/2021/04/30/the-gdb-developers-gnu-debugger-tutorial-part-1-getting-started-with-the-debugger)