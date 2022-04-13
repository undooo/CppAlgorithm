#include "stdc++.h"
using namespace std;
/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *next = head, *last = nullptr;
        while (next)
        {
            next = head->next;
            head->next = last;
            last = head;
            head = next;
        }
        return last;
    }
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        //快慢指针确定链表的中点
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //将中点之后的部分反转
        slow->next = reverse(slow->next);
        //后移slow
        slow = slow->next;
        //循环比较，是否有不同的val
        ListNode *headnode = head;
        while (slow)
        {
            if (headnode->val != slow->val)
            {
                return false;
            }
            headnode = headnode->next;
            slow = slow->next;
        }
        return true;
    }
};