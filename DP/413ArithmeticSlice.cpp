#include "stdc++.h"
using namespace std;
/*
如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。

子数组 是数组中的一个连续序列。

*/

class Solution {
public:
    //动态规划
    //可以分析出的一点是：以某个数字为结尾的等差数列个数，为前一个数字可以形成的等差数列个数+1
    //(在前一个等差数列加上当前数字，总共有n个，另外还多了一个：上一等差数列只取最后两个)
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.empty() || nums.size()<=2) return 0;
        vector<int> dp(nums.size(),0);

        dp[0]=dp[1]=0;
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i]=dp[i-1]+1;
            }
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};