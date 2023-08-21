# Git Handbook

> ***git log 查看源码提交记录***

单行显示某个文件的提交记录：

```shell
git log --oneline <filename>
```



查看某个提交记录的变更情况：

```shell
git show --stat <commitID>        # 其中 commitID 从上一条指令种获取
```



输出某个提交的具体内容：

```shell
git show <commitID>
```



指定日期：

```shell
git log --oneline --since="2023-08-01" --until="2023-08-21" --author="zhangdaoyuan1"
```



> ***git blame 查看源码提交记录***

**某行**

```shell
git blame -L <start_line_number>,<start_line_number> <filename>
```

**连续几行**

```shell
git blame -L <start_line_number>,<end_line_number> <filename>
```



## 参考资料

1. [Git系列讲解：提交记录的使用](https://blog.csdn.net/In_engineer/article/details/127666363)
2. [git log显示特定日期提交](https://www.51cto.com/article/722141.html)
3. [Git指定作者和时间范围](https://blog.csdn.net/lly1122334/article/details/116459113)