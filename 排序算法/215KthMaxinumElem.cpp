#include "stdc++.h"
using namespace std;
/*

给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

*/

class Solution {
public:

    int QuickSelection(vector<int>& nums,int l,int r){
        int first=l,end=r,key=nums[first];
        //得到当前第一个数字的最终所处位置（由于题目要求，此处选择降序）
        while(first<end){
            while(first<end && nums[end]<=key){
                end--;
            }
            nums[first]=nums[end];
            while(first<end && nums[first]>=key){
                first++;
            }
            nums[end]=nums[first];
        }
        nums[first]=key;
        
        return first;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1;
        int mid=QuickSelection(nums,l,r);
        //重复快速选择（基于快排），直至得到target
        while(true){
            if(mid==k-1){
                return nums[mid];
            }else if(mid<k-1){
                l=mid+1;
                mid=QuickSelection(nums,l,r);
            }else{
                r=mid-1;
                mid=QuickSelection(nums,l,r);
            }
        }
        
    }
};