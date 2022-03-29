#include "stdc++.h"
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//非递归写法
ListNode *merge1(ListNode *l1, ListNode *l2)
{
    ListNode *head(0), *node = head;
    while (l1 && l2)
    {
        if (l1.val <= l2->val)
        {
            node->next = l1;
            l1 = l1->next;
        }
        else
        {
            node->next = l2;
            l2 = l2->next;
        }
        node=node->next;
    }
    node->next = l1 ? l1 : l2;
    return head;
}

//递归写法
ListNode * merge2(ListNode*l1,ListNode*l2){
    if(!l1) return l2;
    if(!l2) return l1;

    if(l1->val>l2->val){
        l2->next=merge2(l1,l2->next);
        return l2;
    }else{
        l1->next=merge2(l1->next,l2);
        reutrn l1;
    }
}