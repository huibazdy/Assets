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

4. 部署前预览，命令：`hexo g -d`

5. 同步到github，命令：`hexo deploy`

### 2.5 个性化设置

* **修改作者**

    编辑博客根目录下`_config.yml`中`author`字段（之后预览并同步到github）

* **修改浏览器tag页名称**

    编辑博客根目录下`_config.yml`中`title`字段（之后预览并同步到github）

* **修改博客标题**

    主题目录（themes\fluid）下`_config.yml`中`blog_title`字段（之后预览并同步到github）

* **修改主页正中文字**

    主题目录（themes\fluid）下`_config.yml`中`text`字段（之后预览并同步到github）

* **阅读量统计**

    1. 申请LeanCloud账号（注册后需要实名认证并认证邮箱）
    2. 创建应用，在设置->应用凭证找到`APPID`以及`APPKye`
    3. 创建`_Counter`class用来管理统计数据
    4. 设置网络安全
    5. 云引擎->WEB->部署->创建函数->复制代码->选择`beforesave`以及`Counter`class->部署
    6. 主题目录（themes\fluid）下`_config.yml`中`web analytics`字段为`true`来打开统计开关
    7. 主题目录（themes\fluid）下`_config.yml`中`leancloud`字段，将`APPID`以及`APPKye`复制到相应位置（注意要加一个空格）
    8. 打开计数功能，统计来源设置为leancloud，主题目录（themes\fluid）下`_config.yml`中`views`字段，改`true`，并添加`format: "{} 次"`
    9. 页面底部展示网站PV、UV统计数，主题目录（themes\fluid）下`_config.yml`中`statistics`字段，改`true`，添加`pv_format: "总访问量：{} 次"`以及`uv_format: "总访客数：{} 人"`

* **评论功能**

    1. 启用评论插件：主题目录（themes\fluid）下`_config.yml`中`comments`字段，设置`true`，修改`type`为`valine`
    2. 配置`valine`字段

* **添加文章结束标识**

    themes路径下`_config.yml`中修改

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
4. [阅读量统计](https://cloud.tencent.com/developer/article/1482008)
5. [阅读量统计2](https://bjtu-hxs.github.io/2018/06/12/leancloud-config/)
6. [阅读量统计3](https://finisky.eu.org/hexormleancloud/)
7. [阅读统计量4](https://www.jianshu.com/p/e0a719bac963)
8. [评论问题解决](https://iyichen.xyz/2022/01/hexo-leancloud-valine-access-fail/)



