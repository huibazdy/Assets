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
ListNode* addTwoNumber(ListNode *l1,ListNode *l2)
{
    ListNode *L = new ListNode;  //新链表头结点，之后返回头结点的下一个结点
    ListNode *temp = L;
    
    int carry = 0; //用于进位
    
    while(l1 != nullptr && l2 != nullptr)
    {
        int ans = l1->val + l2->val + carry;
        if(ans > 9)
        {
            ListNode *born = new ListNode;
            born->val = 0;
            carry = 1;
        }
        else
        {
            ListNode *born = new ListNode;
            born->val = ans;
        }
        born->next = nullptr;
        temp->next = born;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    if(l1 == nullptr)
        temp->next = l2;
    else if(l2 == nullptr)
        temp->next = l1;
    
    return L->next;
}
```

