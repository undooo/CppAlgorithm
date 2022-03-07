#include"stdc++.h"
using namespace std;
/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。


*/

class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.empty()) return 0;
        int house=nums.size(),maxProfit=0;
        //只有两种决策：抢当前屋舍/不抢
        vector<int> dp(house+1,0);
        dp[1]=nums[0];
        //遍历每一个房子，最终得出最大利益
        int i;
        for(i=2;i<dp.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[i-1];
    }
};