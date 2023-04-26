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
    }
}
```



> 【**拓展**】
>
> 使用层序遍历模板可以做LeetCode：107 199 637 429 515 116 559