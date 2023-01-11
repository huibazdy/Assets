# 一、需求分析

## 1.1 家庭需求

* 与日俱增的数据量，包括但不限于：照片、视频、电子书、文档、证件等。
* 数据异地上传与下载
* 多设备协同
* 数据传输速度
* 数据安全性：放在第三方服务器总是不放心
* 数据私密性

我们期望的最终效果：



## 1.2 数据存储方案

### 1.2.1 网盘

网盘也称云盘，由云服务商提供数据服务。数据存储容量和传输速度都受限于是否购买会员。应用场景主要包括手机和PC两大终端。

优点：

1. 傻瓜式，交钱就可以用
2. 不用担心备份，服务商有灾备

缺点：

1. 传输速度受限，无论是否购买会员，并不能达到网速限制
2. 数据私密性不够，隐私数据终归在别人手里

### 1.2.2 NAS

可以简单理解为私人云盘，即在自己家里搭建的属于自己的云盘。

具体实现方式分为两种：

1. 黑NAS：自己购买硬件，安装盗版或开源NAS系统，搭建NAS
2. 白NAS：直接购买打包好的NAS服务器，买来即可使用

优点：

1. 使用简单，功能丰富（有各种app支持各种功能），大部分功能都能在手机上操作，包括：照片、文件、视频管理等
2. 支持数据灾备，可以做磁盘阵列（raid0，raid1，raid5，raid10）
3. 具有完整操作系统，就是一台小型服务器，几乎可以支持一个小型公司办公
4. 支持Docker，能搭建服务器
5. 数据安全性极高，不会经过第三方服务器
6. 速度快，能够跑满你的网速上限（内网），外网则依赖于你的网络带宽
7. 具有完整的权限管理策略，可以新建各种成员和人群划分
8. 可以支持视频监控存储
9. 可以大大节省手机空间，数据全部放在NAS
10. 支持BT
11. 支持家庭影院系统

缺点：

1. 搭建教复杂，动手能力要求高
2. 成本较高



方案比较：

|            | 网盘 | NAS  |
| :--------- | :--: | :--: |
| 价格       | 较低 | 较高 |
| 功能       | 一般 | 丰富 |
| 性能       | 较好 |  好  |
| 数据安全性 |  高  | 极高 |
| 数据私密性 | 一般 | 极高 |





# 二、选型

## 2.1 物理平台





## 2.2 软件平台





# 三、软件平台







# 参考资料

1. [为什么你需要一台NAS](https://juejin.cn/post/6988020660039581727)