- [ ] 剑指55
- [ ] LeetCode104



二叉树节点定义：

```c++
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};
```

> 【**树的深度**】
>
> 从根节点到叶子结点依次经过的节点（包含根与叶子结点）形成树的一条***路径***，***最长路径***上的***节点数***为树的深度。



【**递归**】

整颗树的深度可以理解为左右子树深度的最大值加 1。

```c++
int treeDepth(BinaryTreeNode* root)
{
    if(root == nullptr)
        return 0;
    
    int leftDepth = treeDepth(root->left);  //求左子树深度
    int rightDepth = treeDepth(root->right);  //求右子树深度
    
    return (leftDepth > rightDepth) ? (rightDepth + 1) : (rightDepth + 1);
}
```

【**遍历**】

使用[层序遍历](https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247484713&idx=1&sn=2072608d432def7457fdfa27b73d8193&scene=21#wechat_redirect)，层序遍历的层数就是二叉树的深度。

层序遍历的思想是从左至右一层层向下遍历整棵树。需要借助一个辅助数据结构：队列，因为队列适合先入先出的遍历逻辑。

```c++
void levelOrder(BinaryTreeNode* root)
{
    queue<BInaryTreeNode*> q;
    while(root != nullptr)
    {
        visit(root);
        
        //将root的孩子节点插入队列
        if(root->left != nullptr)
            q.push(root->left);
        if(root->right != nullptr)
            q.push(root->right);
        
        //下一个要访问的节点
        root = q.front();
        if(q.empty())
            return;
        else
            q.pop();
    }
}
```



> 【**拓展**】
>
> 使用层序遍历模板可以做LeetCode：107 199 637 429 515 116 559





> 【**平衡二叉树**】
>
> 树的每个节点左右子树深度相差不超过 1

判断一个二叉树是否为平衡二叉树最自然的思路是：遍历树节点，对每个节点调用`treeDepth()`来求子左右子树的深度，然后再判断其左右子树的深度之差是否超过 1 。

```c++
#include "treeDepth.h"

bool isBalanced(BinaryTreeNoode* root)
{
    if(root == nullptr)
        return true;
    
    //判断根节点平衡
    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);
    int diff = leftDepth - rightDepth; 
    if(diff < -1 || diff > 1)
        return false;
    
    //递归调用，判断除根节点外其他节点也平衡
    return isBalanced(root->left) && isBalanced(root->right);
}
```

上述解法简洁，但是带来的问题是除了根节点外其他节点都会被访问多次。



只遍历一次的解法：利用后序遍历，遍历每个节点的时候记录它的深度，一边遍历一边判断节点是否平衡