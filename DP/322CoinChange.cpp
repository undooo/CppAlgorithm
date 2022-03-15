#include"stdc++.h"
using namespace std;

/*
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size=coins.size();
        vector<vector<int>> dp(size+1,vector<int>(amount+1,amount+2));
        for(int i=0;i<=size;i++){
            dp[i][0]=0;
        }

        for(int i=1;i<=size;i++){
            int num=coins[i-1];
            for(int j=0;j<=amount;j++){
                if(j<num){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-num]+1);
                }
            }
        }
        return dp[size][amount]==amount+2?-1:dp[size][amount];
    }
};
//改进后
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //采用压缩后的dp算法
        int size=coins.size();

        vector<int> dp(amount+1,amount+2);
        dp[0]=0;
        for(int i=1;i<=size;i++){
            int w=coins[i-1];
            for(int j=w;j<=amount;j++){
                dp[j]=min(dp[j],dp[j-w]+1);
            }
        }
        return dp[amount]==amount+2?-1:dp[amount];
    }
};