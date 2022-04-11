#include"stdc++.h"
using namespace std;
//求二叉树的最大深度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //递归返回左右子树最大值加一
        return root?max(maxDepth(root->left),maxDepth(root->right))+1:0;
    }
};