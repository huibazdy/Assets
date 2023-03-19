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

    `hexo s`  

3. 生成静态页面 【[命令详解](https://hexo.io/docs/generating.html)】

    `hexo g`

4. 部署到远端服务器 【[命令详解](https://hexo.io/docs/one-command-deployment.html)】

    `hexo deploy`