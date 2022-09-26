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



### 遍历

访问节点的值：

```C++
template <class T>
void visit(binaryTreeNode<T> *node)
{
    cout<<node->value<<' ';
}
```



#### 前序

```C++
template <class T>
void preOrder(binaryTreeNode<T> *root)
{
    if(root != nullptr)
    {
        visit(root);            //访问树根
        preOrder(root->left);   //前序遍历左子树
        preOrder(root->right);  //前序遍历右子树
    }
}
```



#### 中序

```C++
template <class T>
void inOrder(binaryTreeNode<T> *root)
{
    if(root != nullptr)
    {
        inOrder(root->left);
        visit(root);
        inOder(root->right);
    }
}
```



#### 后序

```C++
template <class T>
void postOrder(binaryTreeNode<T> *root)
{
    if(root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        visit()root;
    }
}
```



#### 层序

> 从顶层到底层，每一层从左至右访问

```C++
template <class T>
void levelOrder(binaryTreeNode<T> *root)
{
    arrayQueue<binaryTreeNode<T>*> q;
    while(root != nullptr)
    {
        visit(root);
        //将root的孩子插入队列
        if(root->left != nullptr)
            q.push(root->left);
        if(root->right != nullptr)
            q.push(root->left);
        //提取下一个要访问的节点
        try
        {root = q.front();}
        catch
        (queueEmpty){return;}
        q.pop();
    }
}
```



## 二叉树抽象类

```C++
template <class T>
class binaryTree
{
    public:
        virtual ~binaryTree(){}
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual void preOrder(void(*) (T*)) = 0;
        virtual void inOrder(void(*) (T*)) = 0;
        virtual void postOrder(void(*) (T*)) = 0;
        virtual void leveOrder(void(*) (T*)) = 0;
};
```

