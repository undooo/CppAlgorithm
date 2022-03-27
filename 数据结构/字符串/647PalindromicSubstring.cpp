#include"stdc++.h"
using namespace std;
/*
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

*/

class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        //统计以当前字符为中轴的回文字符串有哪些
        for(int i=0;i<s.size();i++){
            //奇数回文
            count+=extendSub(s,i,i);
            //偶数回文
            count+=extendSub(s,i,i+1);
        }
        return count;
    }
    int extendSub(string s,int left,int right){
        int count=0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
};