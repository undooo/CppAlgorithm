#include "stdc++.h"
using namespace std;
/*

给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
*/

class Solution {
public:
    string frequencySort(string s) {
        //创建一个哈希表，记录各个字母的出现次数
        unordered_map <char,int> counts;
        //记录最大频率，用于创建桶
        int max_freq=0;
        for(const char ch:s){
            max_freq=max(max_freq,++counts[ch]);
        }
        //创建桶
        vector<vector<char>> buckets(max_freq+1);
        for(const auto &p:counts){
            buckets[p.second].push_back(p.first);
        } 
        //创建结果
        string ans;
        for(int i=max_freq;i>=0;i--){
            for(int j=0;j<buckets[i].size();j++){
                for(int k=0;k<i;k++){
                    ans+=buckets[i][j];
                }
            }
        }
        return ans;
    }
};