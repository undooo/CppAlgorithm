#include "stdc++.h"
using namespace std;
/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。


*/
//这个题太tm难
class Solution {
public:

    double GetKthElement(const vector<int>&nums1,const vector<int>&nums2,int k){

        //取a,b两个数组的k/2-1位，并通过判断大小进行相关操作
        //初始化当前指标
        int p1=0,p2=0;
        int size1=nums1.size(),size2=nums2.size();
        //循环直至找到第k小的数字，在该过程中不断更新k
        while(true){
            //判断边界情况，若某一数组已经遍历结束，则直接取另一数组的相应元素
            if(p1==nums1.size()) return nums2[p2+k-1];
            if(p2==nums2.size()) return nums1[p1+k-1];
            if(k==1) return nums1[p1]<nums2[p2]?nums1[p1]:nums2[p2];
            //更新信息
            int new_p1= (p1+k/2-1<size1)?p1+k/2-1:size1-1;
            int new_p2= (p2+k/2-1<size2)?p2+k/2-1:size2-1;
            int val_new1=nums1[new_p1],val_new2=nums2[new_p2];
            //判断两数组当前位置的大小，从而更新信息
            //若a<=b,则说明a前面的部分都可以舍弃
            if(val_new1<=val_new2){
                
                k-=new_p1-p1+1;
                p1=new_p1+1;
            }else{
                
                k-=new_p2-p2+1;
                p2=new_p2+1;
            }
    }
}


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_len=nums1.size(),nums2_len=nums2.size(),k=nums1_len+nums2_len;
        if(k%2==1){
            //若为奇数，则求第k+1/2小的数
            return GetKthElement(nums1,nums2,(k+1)/2);
        }else{
            return (GetKthElement(nums1,nums2,k/2)+GetKthElement(nums1,nums2,k/2 + 1))/2.0;
        }
    }
};