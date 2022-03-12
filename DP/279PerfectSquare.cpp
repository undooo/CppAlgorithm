#include"stdc++.h"
using namespace std;
/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是

*/

class Solution {
public:
    //可以对这个数字进行拆分，拆成1^2+i,2^2+i……
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX-1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};