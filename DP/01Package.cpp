#include"stdc++.h"
using namespace std;

//1.二维dp数组，dp[i][j]表示当背包容量为j时，取前i个物品所能达到的最大利益

//weights和values分别承载所有物品的重量和价值,N为物品数量，W为背包的容量
int _01Package(vector<int> weights, vector<int> values, int N, int W){

    //创建二维dp数组
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));

    //开始遍历
    for(int i=1;i<=N;i++){
        int w=weights[i-1],v=values[i-1];

        for(int j=1;j<=W;j++){

            //若放的下当前物品，则判断怎样取是最大的
            if(j>=w){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+v);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }

    }
    return dp[N][W];
}

//压缩空间方案
int knapsack(vector<int> weights, vector<int> values, int N, int W){
    //由于每一个点的值仅与上一行的元素有关，所以可以转二维为一维
    //也是由于这个原因，需要从后向前遍历，不然在到达该点的时候，前面的元素其实已经更改为当前行的元素了

    vector<int> dp(W+1,0);
    for(int i=1;i<=N;i++){
        int w=weights[i-1],v=values[i-1];
        for(int j=W;j>=w;j--){
            dp[w]=max(dp[j],dp[j-w]+v);
        }
    }
    return dp[W];
}