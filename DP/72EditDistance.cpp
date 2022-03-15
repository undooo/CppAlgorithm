#include"stdc++.h"
using namespace std;
/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符

*/
class Solution {
public:
    //dp方法
    //插入或删除是一类
    //替换是一类
    int minDistance(string word1, string word2) {
        int len1=word1.size(),len2=word2.size();
        //初始化dp数组
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        //逐步更新
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){

                //若是边界点，则更改次数
                if(i==0){
                    dp[i][j]=j;
                }else if(j==0){
                    dp[i][j]=i;
                }else{
                    //对两大种情况（四种细分情况）取最小值
                    dp[i][j]=min(dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1),min(dp[i-1][j]+1,dp[i][j-1]+1));
                }
            }
        }
        return dp[len1][len2];

    }
};