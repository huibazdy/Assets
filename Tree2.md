# 一、树的基本概念





# 二、 树的实现

## 2.1 二叉树实现

### 2.1.1 C实现

```c
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode 
};
```



### 2.1.2 C++实现

```c++
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr);
    TreeNode(int x):val(x),left(nullptr),right(nullptr);
    TreeNode(int x,TreeNode *l,TreeNode *r):val(x),left(l),right(r);
};
```





## 2.2 遍历



# 三、相关题解