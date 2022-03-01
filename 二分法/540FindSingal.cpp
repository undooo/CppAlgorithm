#include "stdc++.h"
using namespace std;
/*
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //首先，确定头部和尾部位置，并确定mid
        int l=0,r=nums.size()-1,mid=0;
        //开始二分法循环
        while(l<r){
            //分析可知
            //在单一元素之前的偶数元素，他们与下一位相同，而奇元素则与前面的元素相同
            //而单一元素之后的则正好相反
            //以此为判断依据，就可实现每次去掉一般的元素，将时间复杂度控制在logn
            mid=(l+r)/2;
            //判断mid为偶数的情况
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    l=mid+1;
                }else{
                    r=mid;
                }
            }else{
                if(nums[mid]==nums[mid-1]){
                    l=mid+1;
                }else{
                    r=mid;
                }
            }
        }
        return nums[l];
    }
};