#include "stdc++.h"
using namespace std;
/*
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。



*/
//1.将根号换地为对数
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};

//2.二分查找
class Solution {
public:
    int mySqrt(int x) {
        //使用二分法求解
        long l=1,r=x,mid=0;
        //Consider the case where x is 0 in isolation
        if(x==0) return 0;
        while(l<=r){
            mid=(l+r)/2;
            if(x/mid==mid){
                return mid;
            }
            else if(mid>x/mid){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return r;
    }
};