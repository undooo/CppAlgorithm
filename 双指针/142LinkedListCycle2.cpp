#include "stdc++.h"
using namespace std;
/*
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
/*
判断有无环只需要设置快慢指针，若快指针能追上慢指针，则说明必定有环，期间判断快指针是否会指向空指针

而判断具体环节点，可以由数学公式推导
假设从头节点到环节点要走m步，环长n，两指针相遇时距离环节点k步，则

对于快指针，走了   m+k+n

    慢指针，走了  m+k

而 m+k+n=2(m+k)
则
n=m+k

意味着快/慢指针只需再走m步，就可到达环节点，同时，从头节点到达环节点也需要m步，所以可以将其中一个返回到头节点，然后各走一步直至相遇，就可到达环节点。

*/
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        //将两指标分别向后运动
        do{
            if(!fast ||!fast->next)return nullptr;
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=slow);
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};