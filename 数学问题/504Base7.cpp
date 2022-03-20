#include"stdc++.h"
using namespace std;
/*
给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。
*/

//主要要考虑负数和0的情况
class Solution {
public:
    string convertToBase7(int num) {
        //首先，判断是否为0或负数的情况
        if(num==0) return "0";
        string ans;
        bool isNeg=num<0;
        if(isNeg) num=-num;
        //整数取余
        while(num){
            int a=num%7;
            num=num/7;
            ans=to_string(a)+ans;
        }
        return isNeg?"-"+ans:ans;
    }
};