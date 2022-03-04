#include"stdc++.h"
using namespace std;
/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。

*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
       
        //双指针法，一个指针交换0，另一个交换2
        int p0=0,p2=nums.size()-1,i=0;
        while(i<=p2){
            
            while(i<=p2 && nums[i]==2){
                swap(nums[i],nums[p2]);
                p2--;
            }
            if(nums[i]==0){
                swap(nums[i++],nums[p0++]);
            }else{
                i++;
            }
        }
        return;
    }
};