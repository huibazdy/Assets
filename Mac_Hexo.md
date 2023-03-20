## 一、安装 Hexo

### 1.1 环境准备

* Git
* Node.js



### 1.2 安装 Hexo

主要分为以下几个步骤

1. 安装 homebrew

2. 安装 git

    `brew install git`

3. 安装 nodejs，

    `brew install node`

4. 查看 nodejs 版本

    `node -v`，`npm -v`

5. 安装 Hexo

    `npm install -g hexo-cli`

    **注意**：若报错可以在命令前加`sudo`再次安装



### 1.3 初始化 Hexo

1. 创建博客根目录

    `mkdir <your_blog_name>`

2. 根目录下初始化 Hexo 环境

    `hexo init <your_blog_name>`

3. 进入根目录并添加 Hexo 支持

    `cd <your_blog_name>`，`npm install`

4. 初始化后，博客根目录下会生成一些文件和文件夹，





## 二、配置 Hexo

在进行进一步配置前，我们可以预览初始化完成后的默认博客样式。首先进入博客根目录，然后通过命令：**`hexo s`** 来本地运行博客站点，并将得到的 URL 复制到浏览器中进行预览。



**Hexo** 博客的大部分配置定义在博客根目录下的 **<_config.yml>** 文件中，可以通过修改该文件来个性化配置博客。



### 2.1 主题

1. 在[主题网站](https://hexo.io/themes/)挑选自己喜欢的主题，例如 ***fluid***
2. 将下载下来的压缩包，解压到博客根目录下的 <**themes**> 文件夹中，并将解压得到的文件夹重命名为***fluid***
3. 打开`_config.yml`配置文件
4. 找到`theme`字段，将默认的`landscape`修改为`fluid`主题，将`language`字段默认值`en`改为`zh-CN`，保存关闭文件
5. 首次使用新主题，需要配置about页面：`hexo new page about`
6. 编辑博客目录下的`index.md`文件，添加`layout: aoubt`字段，保存关闭
7. 本地启动观察效果，依次执行以下指令
    * `hexo clean`（清除旧的生成页面）
    * `hexo g`（生成新的HTML页面）
    * `hexo s`（打开本地站点）



### 2.2 个性化

* ***浏览器 tag 标题***

    根目录 <_config.yml> 中修改`title`字段

* ***浏览器 icon***

    - [x] to do

* ***博文作者***

    根目录 <_config.yml> 中修改`author`字段

* ***博客标题***

    themes\fluid 路径下 <_config.yml> 中修改`blog_title`字段 

* ***博客主页标题***

    themes\fluid 路径下 <_config.yml> 中修改`text`字段

* ***阅读量统计***

    - [x] to do

* ***评论功能***

    - [x] to do



## 三、部署 Hexo

### 3.1 部署到 GitHub

【[参考资料](https://hexo.io/zh-cn/docs/one-command-deployment)】

1. 博客根目录 <_config.yml> 中配置`deploy`字段

    ```bash
    deploy:
      type: git
      repo: https://github.com/huibazdy/huibazdy.github.io
      branch: main
      message: #自定义信息
      token: #令牌认证，如果没有这个，则需要每次上传时提供目标仓库用户名和密码
    ```

2. 安装 **hexo-deployer-git** 插件

    ```bash
    npm install hexo-deployer-git --save
    ```

3. 将当前根目录下站点推送到 github

    ```bash
    hexo clean && hexo deploy
    ```

4. 查看 <Github 用户名>.github.io 网站是否能正常工作



> ***注意***：上传碰到过报错 **Error: Spawn failed** 的情况。可以通过将 repo 字段改为 git@github.com:huibazdy/huibazdy.github.io.git 解决。【[参考](https://blog.zhheo.com/p/128998ac.html)】





## 四、基本命令

1. 新建博文 【[命令详解](https://hexo.io/docs/writing.html)】

    `hexo new "article_name"`

2. 运行本地服务器 【[命令详解](https://hexo.io/docs/server.html)】

    `hexo server`  

3. 生成静态页面 【[命令详解](https://hexo.io/docs/generating.html)】

    `hexo generate`

    功能是将 source 文件夹下的所有 md 文件进行渲染生成 HTML 页面，并将生成的页面放在 public 文件夹下。

4. 部署到远端服务器 【[命令详解](https://hexo.io/docs/one-command-deployment.html)】

    `hexo deploy`

5. 清除之前生成的网页

    `hexo clean`



## 五、写文章

### 5.1 布局

* **三种布局**

    Hexo 定义的三种布局用于创建三种不同的文件，分别是：post、page、draft 。它们会被保存到不同的路径下。自定义的布局和post布局保存路径相同。

    | 布局  | 描述 | 路径           |
    | ----- | ---- | -------------- |
    | post  | 文章 | source/_posts  |
    | page  | 页面 | source         |
    | draft | 草稿 | source/_drafts |

* **默认布局**

    在 _config.yml 中的 default_layout 字段来配置，默认开启的是 post 布局。可以关闭，然后再创建时再指定布局。

* **草稿变文章**

    可以使用命令`hexo publish [post] <title>`将指定草稿移动到 source/_posts 路径下，该命令与`new`命令类似。



### 5.2 创建文章

首先使用以下命令创建文章：

`hexo new [layout] <title>`

如果开启了 _config.yml 中的 default_layout 字段，省略 layout 会直接默认生成 post 布局。



在 md 格式的文章开头处，需要提供一些相关信息来给 Hexo 框架进行渲染，这些信息称为[前置信息](https://hexo.io/zh-cn/docs/front-matter)（front-matter），用`---`符号包起来的部分。包括：

| 配置字段    | 功能                                                         |
| ----------- | ------------------------------------------------------------ |
| title:  #   | 文章标题                                                     |
| cover:      | 文章封面图，图片 URL 链接                                    |
| date:       | 写作日期                                                     |
| tags:       | 文章标签，可以尝试使用[标签插件](https://hexo.io/zh-cn/docs/tag-plugins) |
| categories: | 文章分类                                                     |
| keywords:   | 关键词                                                       |
| comments:   | 是否开启评论功能                                             |



插入图片

- [ ] to do



前置信息示例：

- [ ] to do



文章写作完成后，依次执行下列指令：

1. `hexo clean`（清除旧网页数据）
2. `hexo g`（渲染生成新页面）
3. `hexo s`（本地预览，可省略）
4. `hexo d`（部署到远端服务器）



### 5.3 参考资料

1. [Hexo 博客教程](https://cloud.tencent.com/developer/article/1662733)
2. [Hexo 官方写作教程](https://hexo.io/zh-cn/docs/writing.html)
3. [Hexo 插入图片（详细版）](https://www.jianshu.com/p/f72aaad7b852)
4. [Hexo 图片不显示](https://blog.csdn.net/lwcxy966/article/details/91363965)
5. [Hexo 官方插入图片教程](https://hexo.io/zh-cn/docs/asset-folders#%E7%9B%B8%E5%AF%B9%E8%B7%AF%E5%BE%84%E5%BC%95%E7%94%A8%E7%9A%84%E6%A0%87%E7%AD%BE%E6%8F%92%E4%BB%B6)
6. [Hexo 发布文章](https://www.cnblogs.com/chendh/p/16194370.html)