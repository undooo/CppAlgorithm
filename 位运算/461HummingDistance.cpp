#include"stdc++.h"
using namespace std;
/*
两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。

给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int binar=x^y,ans=0;
        while(binar){
            ans+=binar&1;
            binar>>=1;
        }
        return ans;
    }
};