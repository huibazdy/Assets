# GitHub博客搭建

## 一、准备工作

### 1.1 环境搭建

* 安装Git
* 安装NodeJS

### 1.2 安装Hexo

* Windows

​		在终端输入命令：`npm install -g hexo-cli`

* Mac
    1. 安装 homebrew
    2. 安装 git，`brew install git`
    3. 安装 nodejs，`brew install node`
    4. 查看 nodejs 版本，`node -v`，`npm -v`
    5. 安装 Hexo，`npm install -g hexo-cli`，如果安装报错可以在前面加上`sudo`再次安装





## 二、使用HEXO建站

### 2.1 创建博客根目录

1. 找一个盘符根目录，**`hexo init <blogfolder>`**
2. 切换到建立的blog路径，**`cd <blogfolder>`**
3. 安装HEXO依赖模块，**`npm install`**



**Mac环境：**

1. 创建博客目录，`mkdir <your_blog_name>`
2. 在博客目录下初始化 Hexo 环境，`hexo init <your_blog_name>`



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
8. 本地启动观察效果，依次执行以下指令
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



#### 2.6.3 订阅功能

> 可以理解为订报纸，或者杂志，定期就会放在你住宅邮箱中。通过`RSS`功能，对感兴趣的博客进行实时推送。对于读者而言，这样可以缩减搜索时间，也可以及时获得优质博主的更新，避免被搜索带来的额外信息所干扰。

添加RSS功能按照以下几个步骤：

1. 安装RSS插件：`npm i hexo-generator-feed`
2. 在博客根目录的_config.yml文件中，修改`Extensions`字段





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



## 五、多设备协同

> 【***需求***】
>         在公司电脑A（Windows10）初始化并部署了Hexo博客，希望在家里的电脑也能远程修改博客配置，新建文章等操作。

首先需要理解，在进行`hexo deploy`部署到github的其实是hexo编译后的文件（用来生成网页的文件），并不是在本地源文件。可以看一下在github仓库中的并没有配置文件等源文件：

![image-20230110203419236](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230110203419236.png)

以上的仓库内容其实是本地博客根目录下的`public`路径下的内容：

![image-20230110203515770](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230110203515770.png)

多设备通过Git工具以及github协同，具体步骤为：

1. 在github上新建一个hexo分支；
2. 





## 六、博客管理

### 6.1 几个概念

#### layout

Hexo博客框架中的布局（layout）有默认的三种，分别是：

1. **`post`**，默认布局，对应路径是`source/_posts`
2. **`page`**，
3. **`draft`**，

除了默认布局，还可以自定义布局，自定义布局和post路径布局相同，也将存储到`source/_posts`路径。

与layout有关的命令是：**`hexo new [layout] <filename>`**

#### page

#### draft



### 6.2 国内外分流

> 【**背景**】
>
> 因为github的服务器在国外，所以百度爬虫不能爬取到你托管博客的github服务器。如果你想让百度能检索到你的文章，可以在国内的`coding page`做托管，这样的结果是在国内访问就走coding page，国外就走github page。

具体步骤如下：（[参考做法](https://blog.csdn.net/sinat_37781304/article/details/82729029?spm=1001.2101.3001.6650.6&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-6-82729029-blog-119089190.pc_relevant_3mothn_strategy_recovery&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-6-82729029-blog-119089190.pc_relevant_3mothn_strategy_recovery&utm_relevant_index=13)）





### 6.3 SEO

> SEO的全称是Search Engine Optimization，可以翻译为搜索引擎优化。其目的是利用搜索引擎的规则提高网站在搜索引擎的自然排名（竞价排名之外的排名）。使用SEO后，效果就是你的博客或博客文章更容易被搜索引擎排在前面，自然更容易被人看到。

#### 百度SEO

#### 谷歌SEO





## 七、参考资料

1. [GitHub Page与HEXO搭建个人博客](https://blog.csdn.net/yaorongke/article/details/119089190)
2. [用HEXO搭建博客](http://lowrank.science/Hexo-Github/)
3. [HEXO博客详细教程](https://cloud.tencent.com/developer/article/1662732)
4. [阅读量统计](https://cloud.tencent.com/developer/article/1482008)
5. [阅读量统计2](https://bjtu-hxs.github.io/2018/06/12/leancloud-config/)
6. [阅读量统计3](https://finisky.eu.org/hexormleancloud/)
7. [阅读统计量4](https://www.jianshu.com/p/e0a719bac963)
8. [评论问题解决](https://iyichen.xyz/2022/01/hexo-leancloud-valine-access-fail/)
9. [Hexo最全教程](https://blog.csdn.net/sinat_37781304/article/details/82729029?spm=1001.2101.3001.6650.6&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-6-82729029-blog-119089190.pc_relevant_3mothn_strategy_recovery&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-6-82729029-blog-119089190.pc_relevant_3mothn_strategy_recovery&utm_relevant_index=13)
10. [卜算子引入访问量](https://cloud.tencent.com/developer/article/1404868)
11. [Hexo快速搭建博客](https://juejin.cn/post/7025425691252359181)
12. [Hexo托管到Gitee或GitHub](https://cloud.tencent.com/developer/article/1708815)
13. [四种博客搭建方式](https://segmentfault.com/a/1190000039078837)
14. [Hexo教程——EasyHexo](https://easyhexo.com/)



