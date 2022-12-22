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



## 1.3 构造函数

> **构造函数功能：在创建对象时进行初始化**

三种创建对象的方法：

1. **`Complex c1(1.0,2.0);`**
2. **`Complex c2;`**
3. **`Complex *p1 = new Complex(4);`**

> **Singleton（单例）设计模式**允许把**构造函数声明为private**

不允许外界创建

```c++
class A
{
public:
    static A& getInstance();
    setup() {...}
private:
    A();
    A(const A& rhs);
    ...
};

A& A::getInstance()
{
    static A a;
    return a;
}
```



## 1.4 const成员函数

>  类中的成员函数大致可以分为两种：1）不会改变类中数据；2）可改变类中数据的。

不会改变类中数据的成员函数加上`const`限定符，例如：`double real() const {return re;}`

如果没有加`const`会产生什么后果，看下面这段代码：

```c++
const Complex c1(1,2);   //实例化一个常量对象c1，负数中的实部1和虚部2都不可以改变
cout<<c1.real()<<endl;   //获取实部并打印
cout<<c1.imag()<<endl;   //获取虚部并打印
```

在使用成员函数获取实部时，如果`real()`函数没加const，则会被告知可以改变数据，但调用者c1又声明不可以改变（因为是常量），由于这种矛盾，会导致编译器报错！！

==**注意**==
**在设计类的成员函数时，就应该考虑清楚该函数是否会改变数据成员，若不会，必须加上const！**



## 1.5 传值还是传引用

> ***Passed by value or passed by reference？***

* 由于传值的背后是将数据复制到函数的stack中去，如果数据大，则时间空间消耗都大
* 所以尽量不要用传值的方式来传参
* 引用的底层实现就是指针，传引用就类似于传指针，思想就是一个东西太大了，不采取拷贝方式传入函数，而是传地址
* 参数传递尽量都以引用方式传递



## 1.6 返回值还是返回引用

* 返回值也尽量以引用方式传递



## 1.7 友元

`friend`关键字，可以使类外的函数或其他类，可以访问该类的数据成员：

```c++
class Complex
{
public:
    ...
private:
    double re,im;
    friend Complex& _doapl(Complex*,const Complex&);
};

inline Complex& _doapl(Complex* ths,const Complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths
}
```





# 二、面向对象（下）