/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
*/
#include<stdc++.h>
using namespace std;

class Solution {
public:
    bool PartJudge(string s,int i,int j)
    {
        for(;i<j &&s[i]==s[j];i++,j--);
        return i>=j;
    }
    bool validPalindrome(string s) {
        int fir=0,ed=s.length()-1;
        while(fir<ed){
            if(s[fir]==s[ed]){
                fir++;ed--;
            }
            else{
                return PartJudge(s,fir+1,ed) || PartJudge(s,fir,ed-1);
            }
        }
        return true;
    }
};