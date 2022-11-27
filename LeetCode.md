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
    if(list1 == nullptr && list2 == nullptr)  //两个链表都为空
        return nullptr;
    if(list1 == nullptr && list2 != nullptr)  //1为空2不为空
        return list2;
    if(list2 == nullptr && list1 != nullptr)  //2为空1不为空
        return list1;
    
    ListNode *list;  //声明一个新链表作为结果返回
    
    list1 = list1->next;
    list2 = list2->next
    
    while(list1->next != nullptr && list2->next != nullptr)
    {        
        if(list1.val <= list2.val) 
        {
            list->next = list1;
            list1 = list1->next;
        }
        else
        {
            list->next = list2;
            list2 = list2->next;
        }
        list = list->next;
    }
    
    return list;
}
```

