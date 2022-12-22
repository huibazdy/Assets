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
    #include"complex.h"    //包含自定义头文件<complex.h>
    using namespace std;
    
    int main()
    {
        ...
        return 0;
    }
    ```

* 头文件实现

    ```c++
    #ifndef _COMPLEX_
    #define _COMPLEX_
    
    /*1. 前置声明*/
    class ostream;
    class complex;
    /*2. 类声明*/
    class Complex
    {
    public:
        Complex(double r,double i):re(r),im(i){}
        double real() const {return re;}
        double imag() const {return im;}
    private:
        double re;  //实部
        double im;  //虚部
    };
    /*3. 类定义*/
    
    #endif
    ```

* 模板类

    ```c++
    template<typename T>
    class Complex
    {
    public:
        Complex(T r,T i):re(r),im(i) {}
        T real() const {return re;}
        T imag() const {return im;}
    private:
        T re;
        T im;
    };
    
    //使用模板类
    Complex<double> c1(1.2,0.5);
    Complex<int> c2(2,3);
    ```

    

# 二、面向对象（下）