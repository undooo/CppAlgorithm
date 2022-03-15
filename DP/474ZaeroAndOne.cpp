#include"stdc++.h"
using namespace std;
/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution {
public:

    //依然是类似于背包问题
    //该题是个三维题目

    //首先，要获取该字符串中分别有多少个0，1
    pair<int,int> GetZeroOne(const string & str){
        int zeros=0,ones=0;
        for(const char &c :str){
            c=='0'?zeros++:ones++;
        }
        return make_pair(zeros,ones);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=1;i<=size;i++){
            //获取当前字符串的长度
            pair<int,int> ZAndO=GetZeroOne(strs[i-1]);
            int Znum=ZAndO.first,Onum=ZAndO.second;

            for(int z=0;z<=m;z++){
                for(int o=0;o<=n;o++){
                    if(z>=Znum && o>=Onum){
                        dp[i][z][o]=max(dp[i-1][z][o],dp[i-1][z-Znum][o-Onum]+1);
                    }else{
                        dp[i][z][o]=dp[i-1][z][o];
                    }

                }
            }
        }
        return dp[size][m][n];
    }
};