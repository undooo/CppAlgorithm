#include"stdc++.h"
using namespace std;
/*

给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值
*/



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ansList{};
        //若是空树，则直接返回
        if (root==nullptr) return ansList;
        //设置队列，用于广度优先遍历
        queue<TreeNode*> nodeList; 
        nodeList.push(root);
        while(!nodeList.empty()){
            int LaySize=nodeList.size();
            int LayNum;
            while(LaySize--){
                //将当前节点提出来，并添加其孩子进入队列
                TreeNode * node=nodeList.front();
                nodeList.pop();
                LayNum=node->val;
                if(node->left){
                    nodeList.push(node->left);
                }
                if(node->right){
                    nodeList.push(node->right);
                }
            }
            ansList.push_back(LayNum);
        }
        return ansList;
    }
};