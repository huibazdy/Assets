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

1. 安装`hexo-deployer-git`，命令：`npm install hexo-deployer-git --save`

2. 获取github中的`personal access tokens`

3. 在`_config.yml`中修改`deploy`字段为一下内容：

    ```xml
    deploy:
    	type: git
    	repo: https://github.com/huibazdy/huibazdy.github.io
    	branch: main
    	token: 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
    ```

4. 部署到github，命令：`hexo g -d`

### 2.5 个性化设置



### 2.6 功能添加

#### 2.6.1 阅读量统计



#### 2.6.2 评论功能



## 三、新建文章

### 3.1 图片处理

通过修改`_config.yml`相关配置，可以在生成文章的同时，生成一个同名的资源目录用于存放图片文件。具体修改命令是：`post_asset_folder: true`

### 3.2 新建文章

`hexo new post <filename>`



## 四、小工具

### 4.1 LaTeX

可以利用KLatexFormula工具将编辑好的LaTeX公式转为图片，之后再将公式图片导入Markdown图床。

* [KLatexFormula下载地址](https://klatexformula.sourceforge.io/)

### 4.2 二维码打赏



## 参考资料

1. [GitHub Page与HEXO搭建个人博客](https://blog.csdn.net/yaorongke/article/details/119089190)
2. [用HEXO搭建博客](http://lowrank.science/Hexo-Github/)
3. [HEXO博客详细教程](https://cloud.tencent.com/developer/article/1662732)



