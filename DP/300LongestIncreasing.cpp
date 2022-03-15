#include "stdc++.h"
using namespace std;

/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
*/

class Solution {
public:
    //dp
    //记录每个以i结束的最长递增子序列的个数
    //遍历i之前的元素，判断j是否小于i且子序列更长
    int lengthOfLIS(vector<int>& nums) {
        int size=nums.size();
        vector<int> dp(size,1);

        //遍历所有位置
        for(int i=0;i<size;i++){
            //遍历当前位置前的元素
            for(int j=0;j<i;j++){
                //若该点的值小于i且能够使最大子序列增强，则更改dp
                if(nums[j]<nums[i] && dp[j]+1 >dp[i]){
                    dp[i]=dp[j]+1;                
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};


class Solution {
public:
    //二分法思路
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            //若当前值比arr中最后一位还大，即递增，则将其放到arr尾部
            if(nums[i]>arr.back()){
                arr.push_back(nums[i]);
            }else{
                //否则判断能否将其替代
                auto itr=lower_bound(arr.begin(),arr.end(),nums[i]);
                *itr=nums[i];
            }
        }
        return arr.size();
    }
};