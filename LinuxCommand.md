## 解压缩



### .tar.xz



***命令参数解释***

* `-x`：解压
* `-f`：解压指定压缩文件
* `-v`：显示正在解压的文件名称
* `-C`：解压到指定目录

***解压到当前目录***

```shell
tar -xf archive.tar.xz
```

***解压到指定目录***

```shell
tar -xf archive.tar.xz -C [directory]
```





## 查找文件

* ***locate***：`locate <filename>`（一周更新一次文件库，但效率比find命令高）
* ***find***：`find [path] -name <filename>`

