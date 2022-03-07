#include"stdc++.h"
using namespace std;
/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans{};
        if(nums.empty()) return ans;
        backtracking(nums,ans,0);
        return ans;
    }
    //回溯法
    void backtracking(vector<int> & nums,vector<vector<int>> &ans,int level){
        //若当前level已经到达最大限度，则说明得出了一种排列情况
        if(level==nums.size()-1){
            ans.push_back(nums);
        }


        for(int i=level;i<nums.size();i++){
            swap(nums[i],nums[level]);
            backtracking(nums,ans,level+1);
            swap(nums[i],nums[level]);
        }
    }
};