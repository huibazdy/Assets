# 一、面向对象（上）

## 1.1概述

### 1.1.1 宏观

* 基于对象（不带指针）
* 面向对象（带指针）
* 三个类实现：Complex、String、OPP

### 1.1.2 C++历史

* C++ 98（1.0）
* C++ 11（2.0）

### 1.1.3 C++学习范围

* C++ 语言本身
* C++ 标准库

### 1.1.4 C++与C的区别

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212221130786.png" alt="image-20221222113027612" style="zoom: 25%;" />



## 1.2 头文件与类声明

* 头文件形式，以`<complex.h>`为例

    ```c++
    #ifndef _COMPLEX_
    #define _COMPLEX_
    ...
    #endif
    ```

* 头文件使用

    ```c++
    #include<iostream>
    #include"complex.h"    //包含自定义头文件<comple>
    using namespace std;
    
    int main()
    {
        ...
        return 0;
    }
    ```

    

# 二、面向对象（下）