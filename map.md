map 是 C++ 提供的两种类型的关联容器之一（associative-container）。

map 中存储的元素是关键字值对（key-value），其中关键字起到索引的作用，值则是与索引关联的数据。

map 主要有四种，根据一下几个维度进行分类：

1. 关键字是否允许重复；
2. 元素是否按顺序保存

|                        | 关键字是否允许重复 | 元素是否有序 | 所属头文件            |
| ---------------------- | ------------------ | ------------ | --------------------- |
| **map**                | **×**              | **√**        | **< map >**           |
| **multimap**           | **√**              | **√**        | **< map >**           |
| **unordered_map**      | **×**              | **×**        | **< unordered_map >** |
| **unordered_multimap** | **√**              | **×**        | **< unordered_map >** |



> ***怎样理解 map ？***

现实生活中的电话簿就是一个典型的 map，其中人名是关键字，电话号码是值。

电话簿本质上是一种将人名***映射***到电话号码的手段。

map 类型通常被称为关联数组（associative array）。与普通数组类似，区别在于其下标不必是整数。使用者利用关键字而不是位置来查找值。例如：在电话簿中用人名作为下标来获取号码。



> ***经典案例：单词计数***

```c++
#include<map>

map<string,size_t> cnt;  //声明一个从 string 映射到 size_t 的空 map

string word;

while(cin>>word)
    ++cnt[word];

for(const auto &w : cnt)
    cout<<w.first<<" occurs "<<w.second
    	<<((w.second > 1) ? " times" : " time") << endl;
```



> ***初始化***

1. 空

    `map<string,size_t> cnt;`

2. 列表初始化

    ```c++
    map<string,string> name{{"Zhang","San"},
                            {"Li","Si"},
                            {"Wang","Wu"}};
    ```

    

> ***map 与 multimap 实例***

* map

    电话簿，一个关键字（名字）就对应一个值（电话号码）

* multimap

    词典，一个关键字（单词）对应多个值（释义）。这样的 map 就存在多个重复关键字索引的键值对，虽然关键字相同，但是他们的值不同



> ***pair***

`pair`是一种标准库类型，类似于容器，保存两个数据成员，是一个用来生成特定类型的模板。定义在头文件`<utility>`中。