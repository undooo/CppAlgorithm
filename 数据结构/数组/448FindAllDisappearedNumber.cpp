#include"stdc++.h"
using namespace std;

/*
给定一个长度为n 的数组，其中包含范围为1 到n 的整数，有些整数重复了多次，有些整数
没有出现，求1 到n 中没有出现过的整数。

*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //直接对原数组进行操作
        vector<int> ans;
        for(auto num:nums){
            int pos=abs(num)-1;
            if(nums[pos]>0){
                nums[pos]=-nums[pos];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};