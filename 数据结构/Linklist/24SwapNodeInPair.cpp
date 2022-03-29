#include "stdc++.h"
using namespace std;
/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/
/* *
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *first = head, *second;
        //只要仍存在节点对，就持续反转
        if (first && first->next)
        {
            //先将第一对反转，因为头节点需要保留
            second = first->next;
            first->next = second->next;
            second->next = first;
            head = second;
            //循环翻转
            while (first->next && first->next->next)
            {
                //保存第一个节点
                second = first->next;
                //将头连接至第二个节点
                first->next = second->next;
                //将第一个节点连至下一组的第一个节点
                second->next = second->next->next;
                //将本组第二个节点连至本组第一个节点
                first->next->next = second;
                //重置头
                first = second;
            }
        }
        return head;
    }
};