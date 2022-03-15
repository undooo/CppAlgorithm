#include"stdc++.h"
using namespace std;

//与01背包问题的区别在于，01背包每个物品只可以取一次，而完全背包可以取多次
//因此状态转移方程就发生了改变，之前必须转到i-1，但是现在不需要了

int CompleteKnapsack(vector<int> weights, vector<int> values, int N, int W) {

    vector<vector<int>> dp(N+1,vector<int>(W+1,0));

    for(int i=1;i<=N;i++){
        int w=weights[i-1],v=values[i-1];
        for(int j=1;j<=W;j++){
            if(j>=w){
                dp[i][j]=max(dp[i-1][j],dp[i][j-w]+v);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[N][W];
}

//压缩空间方案
int knapsack(vector<int> weights, vector<int> values, int N, int W) {
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int w = weights[i-1], v = values[i-1];
        for (int j = w; j <= W; ++j) {
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }
    return dp[W];
}