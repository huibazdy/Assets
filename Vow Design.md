# Vow Design

## 声学特征

声学特征是连接音频处理与机器学习的桥梁。

> 特征

特征是可度量、可量化的属性。

例如，人的特征：

* 身高
* 体重
* 性别
* 年龄



> 可量化

这里的特征必须是可量化，可测量的数值特征。例如：身高、体重、性别，其中性别可以用枚举形式表示。



> 什么是好的特征？

* 该特征有足够的信息量：**Informative**
* 该特征有足够的区分度：**Discriminating**
* 该特征有足够的独立性：**Independent**



例如给一个你不了解的人推荐电影，你需要知道他的哪些特征才能推荐出让他满意的电影呢？

此时**身高体重**就不是很适合此时的场景，这些特征可能更适合推荐衣服，这些特征与喜好看什么电影并没有什么必然的联系。

**年龄和性别**呢？可能有帮助，但是区分度没有那么高。

**近期看过**的电影？很可能有帮助。信息量，区分度都够。独立性：这个特征应该只取决于电影偏好，而不是其他的因素。



> 通用机器学习框架

怎样在机器学习框架中使用特征？传统机器学习框架如下：

![image-20230908115121643](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230908115121643.png)

一般收集到的第一手数据无法直接作为机器学习的输入。

机器学习模型的训练或者推理（预测）过程，都是针对特征的。

需要前置特征提取模块来提取特征。



对于声纹识别模型，输入是：语音；输出是：声纹码



## 音频特征

常见音频特征：

* 基频（F0）：foundamental frequency
* 共振峰（F1 和 F2）：Formants
* 声强：Intensity

以上特征都是从整个音频提取出来，因此被称为全局音频特征（global acoustic features，gaf）



但是讨论 gaf 需要平稳信号（stationary signals）才有意义，例如周期信号就是典型的平稳信号。



然而现实中的语音信号大多数都不是平稳信号。因此若用 gaf 来描述音频，就会丢失很多局部信息。



全局特征的另一个问题是对噪声很敏感。



## 短时分析

Short-time Analysis 的核心思想是把音频信号且分为小段，将每一个小段近似当做平稳信号处理。

这些小段信号一般在 10 ms~30 ms 之间。将这些小段声音信号称为帧（Frame）。注意区分此处的帧概念不同于 video 中的视频帧概念。

从采样信号中提取音频帧时，会关注两个参数，分别是：

* 帧大小：frame size
* 帧步长：frame step/stride，两个帧之间相隔的时间或采样点数

这两个参数有三种关系：

1. size > step：一般相邻帧会有重复采样点，也就是有重叠
2. size = step：每个采样点属于且仅属于一个帧，帧之间不会有数据重叠
3. size < step：相邻帧之间存在空隙，要避免，这种情况是从采样信号到帧的转换过程中出现了信息丢失。

从采样信号到帧的划分过程称为分帧（Framing）。



【例】

采样信号：时长为 1 s 的 16 KHz 音频信号。

size：25 ms

step：10 ms

可以分多少帧：1 s / 10 ms = 100

每个帧有多少采样点：25 ms / 1 s * 16 K = 400



## 窗函数

[window function](https://zh.wikipedia.org/zh-hans/%E7%AA%97%E5%87%BD%E6%95%B0) 的作用是为了避免分帧导致的信号不连续性（不连续性会带来额外噪声以及傅里叶变换在分帧边界产生吉布斯现象）。

它的做法是为帧内的每一个采样点乘上一个特定的权重。使靠近分帧边界的地方趋近于零，但靠近帧中心的地方趋近于原始数值。

可以想象出，窗函数的形状应该是一个钟型形状。主要有三种窗函数：

* Gaussian
* Hanning
* Hanmming

![image-20231002171528608](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20231002171528608.png)



## 帧后处理

Frame Post-Processing

特征从经过窗函数的帧中提取，在送入机器学习模型前，有时需要进行帧后处理。三种常见的后处理方法有：

* **帧叠加（Frame Stacking）**

    将相邻帧叠加在一起，组成一个更大的帧

* **降采样（Frame Subsampling）**

    按照一定频率，丢弃掉一些帧

* **正则化（Frame Normalization）**

    将帧里的每一个采样点分别进行正则化，使其符合正态分布



![image-20231002171446052](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20231002171446052.png)



## 时域特征

主要根据上图的特征提取（Feature ）展开。

除了全局和局部特征的分类方法外，还有时域与频域的特征分类。

* 时域特征

    可以直接从波形中的采样点得出的特征，无需进行傅里叶变换。

|                                               | 表示法               | 应用场景                                                     |
| --------------------------------------------- | -------------------- | ------------------------------------------------------------ |
| 短时能量（Short-time energy）                 | 帧内采样点幅度平方和 | 语音活动检测（**Voice Activity Detection**，**VAD**）：也就是监测是否有语音信号，实质上是高能量判断为是，低能量判断为不是。这是一种粗略的做法，一旦包含噪声或者音乐就无法利用短时能量这个特征判断是否有语音信号。 |
| 短时平均幅度（Short-time average magnitude）  |                      | 自动增益控制（**Automation Gain Control，AGC**）：AGC的目的是让音频信号的能量平稳变化，避免音量特别大或特别小。 |
| 短时过零率（Short-time zero cross rate，ZCR） | 信号有多少次穿过y=0  | 一定程度上反映信号频率                                       |
| 短时自相关系数（Short-time autocorrelation）  |                      | 每个 k 值有一组特征，用于基音估算                            |
| 短时平均幅度差函数                            |                      | 每个 k 值有一组特征，用于基音估算                            |
| 短时线性预测编码                              |                      |                                                              |



* 频域特征

    先将波形进行傅里叶变换，在变换后的傅里叶域中提取。



## 傅里叶分析



| 信号类型（Type of Signal）               | 傅里叶分析方法（Fourier Analysis Method）             |
| ---------------------------------------- | ----------------------------------------------------- |
| 周期连续信号                             | 傅里叶级数（Fourier Series）                          |
| 非周期连续信号                           | 连续傅里叶变换                                        |
| 周期离散序列                             | 离散傅里叶级数                                        |
| 非周期离散序列                           | 离散时间傅里叶变换                                    |
| 有限离散序列（Finite Discrete Sequence） | 离散傅里叶变换（**Discrete Fourier Transform，DFT**） |

 短时分析中，经过分帧和窗函数处理的帧内音频信号是有限离散序列。

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20231010103153308.png" alt="image-20231010103153308" style="zoom: 25%;" />



DFT 解读：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20231010103329739.png" alt="image-20231010103329739" style="zoom:25%;" />

复杂度是 N^2 ，不能接收大量数据点，因此引入降低时间复杂度的快速傅里叶变换（Fast Fourier Transform，FFT）：

