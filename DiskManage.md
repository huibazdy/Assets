# 磁盘管理

## df

> 原意为`disk free` ，以磁盘分区为单位查看文件系统，主要信息包括各个硬盘被占用与剩余空间信息



* `df -h`
* `df -hl`



## du

> 原意为`disk usage`，显示磁盘使用情况，用于查看当前目录详细使用信息



* `du -sh [目录名]`
* `du -sm [目录名]`
* `du -h [目录名]`
* `du [文件名]`



## 使用情况

### 1. 全局磁盘使用

`df -h`



### 2. 查看当前目录使用量

`du -hs`



### 3. 查看当前目录下各个子目录的大小

`du -d 1 -h`



## 参考资料

1. [菜鸟教程](https://www.runoob.com/w3cnote/linux-view-disk-space.html)