#include"stdc++.h"
using namespace std;
/*

给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 */

class Solution {
public:

    vector<vector<int>> ans{};
    vector<vector<int>> combine(int n, int k) {
        
        int count=0,level=1;
        vector<int> temp(k,0);
        backtracking(temp,level,count,k,n);
        return ans;
    }

    void backtracking(vector<int>&temp,int level,int count,int k,int n){
        if(count==k) {
        ans.push_back(temp);
        return;}

        for(int i=level;i<=n;i++){
            temp[count++]=i;
            backtracking(temp,i+1,count,k,n);
            count--;
        }
    }
};