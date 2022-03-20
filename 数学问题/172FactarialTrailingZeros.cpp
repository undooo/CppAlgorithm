#include"stdc++.h"
using namespace std;
/*
给定一个整数 n ，返回 n! 结果中尾随零的数量。

提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1

 
*/

class Solution {
public:
    //递归实现
    //可以发现，阶乘结果的每一个0，是由2*5实现的，而显然2的数量远多于5，因此本题实质是需要
    //找出阶乘因子中含有多少个5，展开式子可以发现每5个数就会出现一次五，每25个数就会出现2个5，每125...
    //因此实质是计算n/5+n/25+n/125...
    int trailingZeroes(int n) {
        return n==0?0:n/5+trailingZeroes(n/5);
    }
};