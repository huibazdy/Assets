## 二叉树数组表示



## 二叉树的链表描述

```C++
template<class T>
struct binaryTreeNode
{
    T value;
    binaryTreeNode<T> *left;
    binaryTreeNode<T> *right;
    /**** 构造函数 ****/
    binaryTreeNode(){left = right = NULL;}   //无参数
    binaryTreeNode(const T& theValue)        //一个参数
    {
        value(theValue);
        left = right = NULL;
    }
    binaryTreeNode(const T& theValue,
                   binaryTreeNode *theLeft,
                   binaryTreeNode *theRight) //三个参数
    {
        value(theValue);
        left = theLeft;
        right = theRight;
    }
};
```



## 二叉树常见操作

* 确定树高度
* 确定节点数
* 复制
* 打印树
* 判断树是否相同
* 删除整棵树
* 遍历二叉树