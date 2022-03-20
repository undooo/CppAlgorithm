#include"stdc++.h"
using namespace std;
/*
给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。

实现 Solution 类：

Solution(ListNode head) 使用整数数组初始化对象。
int getRandom() 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。


*/


 
 
class Solution {

private:
    ListNode *Listhead;
public:
    Solution(ListNode* head):Listhead(head) {}
    //水库随机取值法
    int getRandom() {
        int ans=Listhead->val;
        ListNode *node=Listhead->next;
        int i=2;
        while(node){
            //水库法取值
            if(rand()%(i++)==0) ans=node->val;
            node=node->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */