#include"stdc++.h"
using namespace std;

//判断一棵树是不是平衡二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //求深度
    int maxDepth(TreeNode *root){
        return root?max(maxDepth(root->left),maxDepth(root->right))+1:0;
    }
    bool isBalanced(TreeNode* root) {
        //保证自己是平衡的
        if(!root) return true;
        bool self=root?abs(maxDepth(root->left)-maxDepth(root->right))<=1:true;
        //保证左右子树也是平衡的
        if(!isBalanced(root->left) || !isBalanced(root->right)) return false;
        
        return self;
    }
};