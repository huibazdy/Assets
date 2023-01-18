# 一、需求分析

## 1.1 家庭需求

* 与日俱增的数据量，包括但不限于：照片、视频、电子书、文档、证件等。
* 数据异地上传与下载
* 多设备协同
* 数据传输速度
* 数据安全性：放在第三方服务器总是不放心
* 数据私密性
* 灾备

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



方案对比：

|                | **网盘** | **NAS** |
| :------------- | :------: | :-----: |
| **价格**       |   较低   |  较高   |
| **功能**       |   一般   |  丰富   |
| **性能**       |   较好   |   好    |
| **数据安全性** |    高    |  极高   |
| **数据私密性** |   一般   |  极高   |





# 二、选型

## 2.1 物理平台

树莓派4b（内存4G），其配置已经吊打主流群晖等商用NAS物理主机了。

树莓派配件：

* 电源线：5V 3A
* SD卡
* 读卡器
* 外壳或支架
* 散热片
* 风扇



NAS数据组件：

* 硬盘底座
* 机械硬盘



## 2.2 软件平台

* 安装树莓派镜像
* 安装Samba文件共享服务
* 挂载硬盘
* 设置自动挂载硬盘到共享目录
* 添加NTFS文件系统支持（修改树莓派）或格式化硬盘为EXT4（修改硬盘）
* 配置NextCloud（如果不需要nextcloud网盘的备份、同步等功能，安装Samba就足够使用了）
* 配置内网穿透服务
* Docker，方便部署软件（可选）





# 三、软件平台

## 3.1 树莓派操作系统安装

### 准备工作

1. 下载树莓派镜像（**Raspberry Pi OS with desktop and recommended software**），[下载地址](https://www.raspberrypi.com/software/operating-systems/)
2. 下载并安装官方烧录工具（**Raspberry Pi Imager**），[下载地址](https://www.raspberrypi.com/software/)
3. 将镜像写入SD卡
4. 烧录完成后会弹出格式化窗口，不要格式化，点击取消即可

### 安装操作系统

1. 插入烧录好系统的SD卡
2. 连接输入设备：鼠标、键盘
3. 连接显示器：micro HDMI转HDMI转接头，HDMI线，显示器
4. 连接网线（可选）
5. 连接电源线（上电），树莓派会直接自己启动（红灯亮起，绿灯闪烁）

### 基础配置

【[参考资料](https://ost.51cto.com/posts/2620)】

初次启动后需要进行一些基础配置，后续也可以使用`raspi-config`命令配置。

* 账户
* 分辨率
* 语言
* 网络



* [更换源](https://ost.51cto.com/posts/2620?u_atoken=53e53fcb-4954-4ec1-abbf-275d10a9b9f1&u_asession=01Vw6qZNXEyW_Wg9iZStkmmbGX9Zo3AhdMf0G6KXrNuNIRrJ8L04BvxcAnBpB78EVKX0KNBwm7Lovlpxjd_P_q4JsKWYrT3W_NKPr8w6oU7K-e8nGvPlpZ2Taj0hvgeo_f8-gPxHLWqFpAa4HSYAbXp2BkFo3NEHBv0PZUm6pbxQU&u_asig=053rs23s8kYv45len_QlH5shVXKvKBtstJwCObRpUL4vQfr0rZn4mA65oMefxWwzr1dRJTWwNlYdxidPrKqxSXcekb949n9VfD3N_OrQWneH8onxnqarZKk1HzOQgkhs7dKP9pMJemc34i2tqJOb0cwKtiyObXlxo9q6ypv5wbff_9JS7q8ZD7Xtz2Ly-b0kmuyAKRFSVJkkdwVUnyHAIJzWFbzKd6WSIm8XGMobeH55xZtiSmo5M_TQ4emqkL9Y9F1-9VLfrfHBAsIx5N72vi4-3h9VXwMyh6PgyDIVSG1W_vrCW_JwV1UK9ZLyuNgEAkPsJ-mQbCrKuRU9-_GaVpXL5ulYzyvHM7wc9fK_YjcrArTa1Et6DRF9ze-a3VpN3rmWspDxyAEEo4kbsryBKb9Q&u_aref=RVXPbZPeLBTP3Gunixq7NYNZa30%3D)
* 配置ssh
* [输入法](https://wiki.diustou.com/cn/%E6%A0%91%E8%8E%93%E6%B4%BE%E7%B3%BB%E5%88%97%E6%95%99%E7%A8%8B%EF%BC%9A%E4%B8%AD%E6%96%87%E8%BE%93%E5%85%A5%E6%B3%95)

### 远程访问

【**参考资料**】

1. [官方文档](https://www.raspberrypi.com/documentation/computers/remote-access.html)



有时候我们不需要显示器，比如搭建家用NAS，完全不需要有一个显示器持续连接树莓派并开着。有时我们异地想要操控树莓派，也没法通过显示器来进行UI操作。所以利用另一台电脑远程操控树莓派是一个刚需。主要有两种解决方案：`SSH`和`VNC`。

* **获取树莓派IP地址**

在这之前需要明确的是，如果你要在另一台电脑上连接或者说访问树莓派，你需要知道树莓派的`IP`地址。这里获取树莓派IP有两种情况，一种是树莓派连接显示器，另一种是不连接。

任何一台连接`LAN`的设备都会被分配一个IP地址。

对于第一种情况，只需在终端中输入命令`hostname -I`即可获取已连接到LAN上的树莓派的IP地址。

对于第二种情况，使用命令：`ping <hostname>.local`，默认情况下hostname是raspberry。

也可以使用`nmap`（Network Mapper），它是一个免费开源的跨平台网络搜索工具，Mac或Windows环境可以使用[官网地址](https://nmap.org/download.html)下载。Linux环境使用命令`sudo apt-get install nmap`来安装。使用nmp工具可以扫描连接在你的网络上的所有设备。

在使用nmap之前，你需要知道树莓派连接网络的子网号（subnet），子网号可以通过你操作的电脑（与树莓派在同一个局域网内）的IP地址来获取，例如你当前电脑的IP地址是`192.168.1.5`，那么树莓派所在的子网号就是`192.168.1`。

接下来就可以利用nmap命令`sudo nmap -sn 192.168.1.0/24`来列出在这个子网上的所有设备的IP地址。结果列表中，raspberry字段后面跟着的就是树莓派的IP地址。注意，因为要看到hostname，所以需要在nmap命令前加上sudo。

* **配置SSH服务器**

首先需要明确的是，你可以利用==**SSH**==协议在同一局域网的另一台设备上远程获取树莓派的==**命令行**==。

如果你想远程获取整个树莓派桌面而不仅仅是命令行，就需要用到VNC工具。

配置SSH的步骤如下：

1. 确保树莓派已配置安装好且连网，无线或有线连接
2. 记下自己树莓派的IP地址，为之后远程连接做准备
3. 利用`ipconfig`找到当前电脑（Windows）的IP地址
4. 手动打开树莓派SSH Server，其SSH Server默认是关闭的，步骤如下：
    * 左上树莓图标->Preference->Raspberry Pi Configration->打开SSH->点击OK
    * 也可以使用命令行来实现相同效果：
        * `sudo raspi-config`
        * 选择`Interface Options`
        * 找到最后的`SSH`
        * 选择`Yes`
        * 选择`Finish`
5. 从Linux电脑或Mac电脑亦或是另一个树莓派利用SSH访问树莓派不需要安装额外软件，只需要使用命令：`ssh hostname@<IP>`，用树莓派IP替换其中的IP即可。当连接开始工作后，你会看到一个Warning，点击yes即可。hostname默认是pi，但是我初次进系统时已经改成了zdy，ssh使用时记得使用最新的hostname才能连接上。最后输入用户密码即可连接（亲试MacBook可用）。
6. 在Windows环境SSH访问树莓派，同上，2018年后也不需要第三方软件了。



* **不需要输入密码的SSH登录**

为了达到不需要每次输入密码来登录ssh的效果，需要用到一个叫作`ssh key`的东西。

1. 生成ssh key

    在你需要连接树莓派的电脑上生成ssh key，在此之前你需要检查目前电脑上是否已经有ssh key了，需要用到命令`ls ~/.ssh`，如果结果列表中有`id_rsa.pub`或`id_dsa.pub`就说明此电脑已经有ssh key了。如果没有就需要使用命令`ssh-keygen`来生成ssh key。

2. 找到公钥`id_rsa.pub`

    在`~/.ssh`路径下会生成一个公钥id_rsa.pub以及一个私钥`id_rsa`。

3. 将公钥复制到树莓派



* **开启VNC**

【[参考资料](https://www.labno3.com/2021/08/03/setting-up-a-vnc-server-on-the-raspberry-pi/)】

虚拟网络计算（Virtual Network Computing，VNC）。在不方便直接操作树莓派的时候，有时候需要远程完全获取树莓派桌面来方便操作，而不是仅仅利用ssh获取其命令行操作权。

VNC是一个图形桌面共享系统，通过VNC你可以利用一台电脑（运行VNC Viewer）远程操控另一台电脑（运行VNC Server）的图形界面。VNC Viewer会发送键盘以及鼠标的触碰事件（touch event）给VNC Server并且接收到反馈。

最终的效果是树莓派桌面在你的远程操控电脑中的一个小窗口内。

树莓派上同时装有VNC Server和VNC Viewer，但是需要使能VNC才能使用，在带图形化的树莓派上使能：Menu->Preference->Raspberry Pi Configration->Interfaces->VNC->OK



# 参考资料

1. [为什么你需要一台NAS](https://juejin.cn/post/6988020660039581727)
2. [树莓派搭建个人网盘](https://zhuanlan.zhihu.com/p/64055553)
3. [树莓派搭建全功能NAS服务器](https://zhuanlan.zhihu.com/p/399748795)
4. [树莓派搭建私人网盘](https://zhuanlan.zhihu.com/p/364641320)
5. [树莓派搭建NAS详细过程](https://www.jb51.net/article/233859.htm)
6. [树莓派自建NAS云盘](https://zhuanlan.zhihu.com/p/46653100)
7. [丢石头](https://wiki.diustou.com/cn/%E9%A6%96%E9%A1%B5)
8. [树莓派搭建家用NAS](https://juejin.cn/post/7005784829979525157)
9. [树莓派搭建NAS系统OMV](https://post.smzdm.com/p/az6m64er/)
10. [自己动手搭建NAS和流媒体服务器](https://www.packetmania.net/2021/12/19/RPi-NAS-Plex/)