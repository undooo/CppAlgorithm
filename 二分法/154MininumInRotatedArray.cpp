#include "stdc++.h"
using namespace std;

/*
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

你必须尽可能减少整个过程的操作步骤。


*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        //二分查找，直接找位置
        int l=0,r=nums.size()-1,mid=0;
        while(l<r){
            mid=(l+r)/2;
            
            //判断是否比右边界小,若是则右边单增,min的位置一定在mid的左面
            if(nums[mid]<nums[r]){
               r=mid;
            //若比右边界大，则min的位置一定位于mid的右面   
            }else if(nums[mid]>nums[r]){
               l=mid+1;

            //最后是相等的情况，若相等，则无法确定具体情况，但是右端点必定可以舍弃
            }else{
                r--;
            }
        }
        return nums[l];

    }
};