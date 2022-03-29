#include "stdc++.h"
using namespace std;
/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
*/

class Solution
{

public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0, psnm = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for (int i : nums)
        {
            psnm += i;
            res += hash[psnm - k];
            hash[psnm]++;
        }
        return res;
    }
};