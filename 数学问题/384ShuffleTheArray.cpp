#include"stdc++.h"
using namespace std;

/*
给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。打乱后，数组的所有排列应该是 等可能 的。

实现 Solution class:

Solution(int[] nums) 使用整数数组 nums 初始化对象
int[] reset() 重设数组到它的初始状态并返回
int[] shuffle() 返回数组随机打乱后的结果

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shuffle-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    Solution(vector<int>& nums) {
        this->origin=nums;
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        if(origin.empty()) return {};
        vector<int> shuffled(origin);
        int n=origin.size();
        //Fisher-yates洗牌
        for(int i=0;i<n;i++){
            swap(shuffled[i],shuffled[i+rand()%(n-i)]);
        }
        return shuffled;
    }
private:
    //保存初始版本的数组
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */