## 链表

### 【21】合并两个有序链表

将两个升序链表合并为一个新的升序链表并返回，新链表通过给定链表的所有节点组成



<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202211271947568.png" alt="image-20221127194734525" style="zoom:50%;" />

```C++
/*Definition of single-linked list
struct ListNode
{
	int val;
	ListNode *next;
	ListNode():val(0),next(nullptr){}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x,ListNode *next):val(0),next(next){}
};
*/

ListNode* mergeTwoLists(ListNode *list1,ListNode *list2)
{
    //使用带头结点的链表方案
    
    ListNode *list = new ListNode;  //声明一个新链表作为结果返回
    ListNode *temp = list；  //用于新链表生成，会变
    
    while(list1 != nullptr && list2 != nullptr)
    {        
        if(list1.val <= list2.val) 
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    
    return list->next;  //因为采用的是带头结点的链表，所以返回首节点需要指向下一个位置
}
```



### 【2】两数相加

两个非空链表，表示两个非负整数，它们的每位数字按逆序存储，将两数相加并按相同形式链表返回。

输入：L1=[2,4,3]，L2=[5,6,4]

输出：L=[7,0,8]

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202211281653113.png" alt="image-20221128165316005" style="zoom:67%;" />

```C++
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode *L = new ListNode;  //新链表头结点，之后返回头结点的下一个结点
    ListNode *temp = L;  //临时节点，用来链接新创建的节点
    
    int carry = 0; //用于进位
    
    while(l1 != nullptr && l2 != nullptr)
    {
        ListNode *born = new ListNode;
        int ans = l1->val + l2->val + carry;
        if(ans > 9)
        {
            born->val = ans % 10;
            carry = ans / 10;
        }
        else
        {
            born->val = ans;
            carry = ans / 10;
        }
        born->next = nullptr;
        temp->next = born;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    if(!l1 && !l2)    //两个链表长度相等
    {
        if(carry) //处理进位
        {
            ListNode *born = new ListNode;
            born->val = carry;
            born->next = nullptr;
            temp->next = born;
        }
        else
        {
            return L->next;  //此处可以省略
        }
    }

    if(!l2)      //l1比l2长，l2先遍历完
    {
        while(l1)
        {
            ListNode *born = new ListNode;
            int ans = l1->val + carry;
            if(ans > 9)
            {
                born->val = ans % 10;
                carry = ans / 10;
            }
            else
            {
                born->val = ans;
                carry = ans / 10;
            }         
            born->next = nullptr;
            temp->next = born;
            temp = temp->next;
            l1 = l1->next;
        }
        if(carry)  //处理进位
        {
            ListNode *born = new ListNode;
            temp->next = born;
            born->val = carry;
            born->next = nullptr;
        }
    }
    
    if(!l1)    //l2比l1长，l1先遍历完
    {
        while(l2)  
        {
            ListNode *born = new ListNode;
            int ans = l2->val + carry;
            if(ans > 9)
            {
                born->val = ans % 10;
                carry = ans / 10;
            }
            else
            {
                born->val = ans;
                carry = ans / 10;
            }
            born->next = nullptr;
            temp->next = born;
            temp = temp->next;
            l2= l2->next;
        }
        if(carry)  //处理进位
        {
            ListNode *born = new ListNode;
            temp->next = born;
            born->val = carry;
            born->next = nullptr;
        }
    }
    
    return L->next;
}
```



### 【19】删除链表的倒数第N个节点

给定一个链表，删除链表倒数第n个节点，并返回链表头结点。

已知：

* 节点数为：`sz`，且`1 <= sz <= 30`
* n满足：`1 <= n <= sz`

```C++
ListNode* removeNthFromEnd(ListNode *head,int n)
{
    int sz = 1;              //存储链表元素个数
    ListNode *temp = head;   //用于遍历链表来计算链表元素个数
    while(temp->next != nullptr)
    {
        ++sz;
        temp = temp->next;
    }
    
    if(n <= sz)   //如果输入n超出元素总个数则无意义
    {
        int m = sz - n + 1;   //倒数第n个节点就是正数第m个节点
        ListNode *dummy = new ListNode;  //新建哑结点
        dummy->next = head;   //哑结点链接到现在的头结点
        ListNode *pre = dummy;   //用来记录要删除节点的前一个节点，初始化为哑结点
        for(int i = 1; i < m ; i++)  
        {
            pre = pre->next;    //找到要删除节点的前一个位置
            head = head->next;  //找到要删除的节点
        }
        pre->next = head->next; //删除节点
        delete head;
        return dummy->next;
    }
    return head;
}
```



### 【24】两两交换链表中的节点

> 节点数目范围：`[0,100]`



```c++
ListNode* swapPairs(ListNode *head)
{
    int sz;  //用来记录链表元素个数
    while(head != nullptr)
    {
        ++sz;
        head = head->next;
    }
    
    if(sz <= 1)   //链表中没有元素或只有一个元素
        return head;
    
    ListNode *ans = head;  //用于返回交换后的链表
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast != nullptr)
    {
        //交换两个节点
        ListNode *temp = fast->next;
        fast->next = slow;
        slow->next = temp;
        //移动两个定位指针，移动距离为2，此时slow在前，fast反而在后，需要调换一次
        temp = fast;
        fast = slow;
        slow = temp;
        //移动
        slow = slow->next->next;
        fast = fast->next->next;
    }
    return ans;
}
```

官方题解：

```C++
ListNode* swapPairs(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *temp = dummy;
    while(temp->next != nullptr && temp->next->next != nullptr)
    {
        ListNode *slow = temp->next;
        ListNode *fast = temp->next->next;
        temp->next = fast;
        slow->next = fast->next;
        fast->next = slow;
        temp = slow;
    }
    return dummy->next;
}
```



### 【61】旋转链表

> 将链表的每个节点向右移动`k`个位置

![image-20221203164428476](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212031644632.png)

![image-20221203164524684](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212031645726.png)

设链表长度为`n`

如果旋转次数为`n` 的整数倍则还原，即实际旋转长度为`m = k % n`

实际上旋转`m`个位置，就是将最后的`m`个元素组成的链表拼接到开头。

```c++
ListNode* rotateRight(ListNode* head,int k)
{   
    int n = 0;  //存储链表长度
    ListNode *temp = new ListNode;//用于遍历链表来计算表长
    temp = head;
    while(temp)  //计算链表长度
    {
        ++n;
        temp = temp->next;
    }
    
    int m; //存储实际旋转长度
    if(n != 0)  //防止除数为0报错
        m = k % n;
    else
        return head;
    
    if(k == 0 || m == 0 || head == nullptr || head->next == nullptr) //边界条件
        return head;
    
    ListNode *newStart = new ListNode;
    ListNode *oldEnd = new ListNode;
    ListNode *newEnd = new ListNode;
    newStart = oldEnd = newEnd = head;
    
    //移动m次找到新的表头节点
    int movTimes = n - m;
    while(movTimes-- && newStart->next != nullptr)
        newStart = newStart->next;
    //找到新的链表结尾
    while(newEnd->next != newStart)
        newEnd = newEnd->next;
    //移动n-1次找到原链表尾部节点
    while(oldEnd->next != nullptr)
        oldEnd = oldEnd->next;
    
    newEnd->next = nullptr;  //断开新表尾部与新表头部
    oldEnd->next = head;     //拼接
    
    return newStart;         //返回新表头
}
```



### 【83】删除已排序链表中的重复值

给定链表默认按升序排列：

![image-20221205145927617](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212051459678.png)

```C++
ListNode* deleteDuplicates(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)  //边界条件
        return head;

 	ListNode *slow = new ListNode;
    ListNode *fast = new ListNode;
    slow = head;
    fast = slow->next;
    while(fast != nullptr)
    {
        if(slow->val < fast->val) //依然有序，且不重复
        {
            slow = slow->next;
            fast = fast->next;
        }
        else  //存在重复项情况（前提是链表有序，所以只剩下相等的情况），删除重复项
        {
            slow->next = fast->next;
            fast = slow->next;
        }
    }
    return head;       
}
```

执行结果：

![image-20221205151810113](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212051518158.png)



### 【82】删除已排序链表中的重复值2

> 和上题不同的是，此题需要删除出现重复的数值所对应的所有节点

![image-20221205153615251](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212051536308.png)

【**官方题解**】

> 因为重复元素可能出现在链表的开头，所以`head`可能会变，故而需要添加哑结点`dummy`

```c++
ListNode* deleteDuplicates(ListNode* head)
{
    //边界条件：无节点或只有一个节点
    if(head == nullptr || head->next == nullptr)
        return head;
    
    //添加哑结点，并链接到当前head元素
    ListNode *dummy = new ListNode(0,head);
    
    ListNode *cur = new ListNode;      //声明一个用来遍历链表的节点指针：cur
    cur = dummy;                       //为什么初始化为dummy而不是head？？？             
    
    //为了适用while中的条件，才将cur初始化为dummy而不是head
    while(cur->next != nullptr && cur->next->next != nullptr)
    {
        if(cur->next->val == cur->next->next->val)
        {
            int temp = cur->next->val;                   //记录重复的值
            while(cur->next && cur->next->val == temp)     //继续向后遍历直到出现不同的值
                cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return dummy->next;
}
```















### 【206】反转链表

```C++
ListNode* reverseList(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    
    ListNode *start = new ListNode;
    ListNode *end = new ListNode;
    start = end = head;
    
    while(end->next != nullptr)  //找到尾部元素
        end = end->next;
}
```

