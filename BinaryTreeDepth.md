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



【**方法一：递归**】

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

【**方法二：层序遍历**】

使用[层序遍历](https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247484713&idx=1&sn=2072608d432def7457fdfa27b73d8193&scene=21#wechat_redirect)，层序遍历的层数就是二叉树的深度。

层序遍历的思想是从左至右一层层向下遍历整棵树。需要借助一个辅助数据结构：队列，因为队列适合先入先出的遍历逻辑。

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return ret;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/binary-tree-level-order-traversal/solution/er-cha-shu-de-ceng-xu-bian-li-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



```c++
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> ret;
    if(root == nullptr)
        return ret;
    
    queue<TreeNode*> q;
    
    q.push(root);
    while(!q.empty())
    {
        int currentLevelSize = q.size();
        ret.push_back(vector <int> ());
        for (int i = 1; i <= currentLevelSize; ++i)
        {
            
        }
    }
}
```





> 【**拓展**】
>
> 使用层序遍历模板可以做LeetCode：107 199 637 429 515 116 559



【**方法三：后序遍历**】





> 【**平衡二叉树**】
>
> 树的每个节点左右子树深度（或者说高度）相差不超过 1

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



只遍历一次的解法：利用**后序遍历**，遍历每个节点的时候记录它的深度，一边遍历一边判断节点是否平衡。





> 二叉树常见概念



|                | 节点                                                 | 树                     |
| -------------- | ---------------------------------------------------- | ---------------------- |
| 深度（Depth）  | root 到某节点唯一路径的长度，root 深度为 0           | 所有叶节点深度的最大值 |
| 高度（Height） | 某个节点到它所能到叶节点路径的最大值，叶节点高度为 0 | 等于 root 高度         |
| 度（Degree）   | 该节点的孩子数量                                     | 节点度的最大值         |

* **小结**

    树的高度与深度是相等的，从定义可以看出它们都是从 root 到所有叶节点路径中的最大值。前者是向上增长到root，后者是向下深入到所有叶子节点。

* **注意**

    有些地方定义 root 的深度不是从 0 开始的，而是从 1 开始的，如 LeetCode 中。 







