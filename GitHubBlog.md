# GitHub博客搭建

## 一、准备工作

### 1.1 环境搭建

* 安装Git
* 安装NodeJS

### 1.2 安装Hexo

在终端输入命令：**`npm install -g hexo-cli`**

## 二、使用HEXO建站

### 2.1 创建博客根目录

1. 找一个盘符根目录，**`hexo init <blogfolder>`**
2. 切换到建立的blog路径，**`cd <blogfolder>`**
3. 安装HEXO依赖模块，**`npm install`**

### 2.2 本地启动

* `hexo g`

* `hexo s`

* 访问上述命令后出现的网址：http://localhost:4000/

> 本地启动的作用是在写好文章后，在本地进行网站预览，确认无误后再推送到服务器上。

### 2.3 更改主题

1. 挑选喜欢的主题，[挑选网址](https://hexo.io/themes/)
2. 下载`fluid`主题，[下载地址](https://github.com/fluid-dev/hexo-theme-fluid/releases)
3. 将下载下来的压缩包，解压到博客根目录下的`themes`文件夹下，并将解压得到的文件夹重命名为`fluid`
4. 打开`_config.yml`配置文件
5. 找到`theme`字段，将默认的`landscape`修改为`fluid`主题，将`language`字段默认值`en`改为`zh-CN`，保存关闭文件
6. 首次使用新主题，需要配置about页面：`hexo new page about`
7. 编辑博客目录下（E:\Blog\source\about）的`index.md`文件，添加`layout: aoubt`字段，保存关闭
8. 本地启动观察效果，依次执行一下指令
    * `hexo clean`（修改配置文件后，清除旧的生成页面）
    * `hexo g`（生成新的HTML页面）
    * `hexo s`（打开本地站点）

### 2.4 部署到github





## 参考资料

1. [GitHub Page与HEXO搭建个人博客](https://blog.csdn.net/yaorongke/article/details/119089190)
2. [用HEXO搭建博客](http://lowrank.science/Hexo-Github/)
3. [HEXO博客详细教程](https://cloud.tencent.com/developer/article/1662732)

