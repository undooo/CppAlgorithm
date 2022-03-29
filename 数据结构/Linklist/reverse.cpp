#include "stdc++.h"
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//递归写法

ListNode *reverseList(ListNode *head, ListNode *ptr = NULL)
{
    if (!head)
        return ptr;
    ListNode *next = head->next;
    head->next = ptr;
    return reverseList(next, head);
}

//非递归写法
ListNode *reverseList2(ListNode *head)
{
    if (!head)
        return head;
    ListNode *next, *prev = NULL;
    while (next)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}