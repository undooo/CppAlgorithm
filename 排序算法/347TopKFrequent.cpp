#include "stdc++.h"
using namespace std;
/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //第一步，创建一个哈希表，对应各个数字以及出现次数
        unordered_map <int,int> counts;
        //记录最大频率，用于设置之后桶的个数
        int max_freq=0;
       for(const int num:nums){
           max_freq=max(max_freq,++counts[num]);
       }
       //设置桶二维数列,长度即为最大频率数
       vector<vector<int>> bucket(max_freq+1);
       for(const auto &p:counts){
           bucket[p.second].push_back(p.first);
       }
       //求解
       vector<int> ans;
       for(int i=max_freq;i>=0 && ans.size()<k;i--){
           //从后向前遍历，将出现频率最多的依次放入数组
           for(int j=0;j<bucket[i].size()&&ans.size()<k;j++){
               ans.push_back(bucket[i][j]);
           }
       }
       return ans;
    }
};