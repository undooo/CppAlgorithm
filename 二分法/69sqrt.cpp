#include "stdc++.h"
using namespace std;
/*
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

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