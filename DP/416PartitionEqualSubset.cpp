#include"stdc++.h"
using namespace std;

/*
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 */

class Solution {
public:


    //等价于01背包问题
    //即前i个物品，是否能够挑选一部分，使得和为一
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        int target=sum/2,size=nums.size();
        vector<vector<bool>> dp(size+1,vector<bool>(target+1,false));
        //初始化操作
        for(int i=0;i<=size;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=size;i++){
            int numi=nums[i-1];
            for(int j=1;j<=target;j++){
                //若放不下当前元素，则结果取决于在i-1情况下，是否可以满足j
                if(numi>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    //否则取决于以下两种情况
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-numi];
                }
            }
        }
        return dp[size][target];
    }
};