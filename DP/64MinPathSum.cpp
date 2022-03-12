#include"stdc++.h"
using namespace std;
/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步
*/
class Solution {
public:
    //动态规划
    //对于每一个点，到达该点的最短路径为min（上+该点，左+该点）
    //需要考虑边界情况
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int row=grid.size(),col=grid[0].size();
        //设立dp数组保存结果
        vector<vector<int>> dp(row,vector<int>(col,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                //对于左上边界的格子，单独判断
                if(i==0 && j==0) continue;
                if(i==0){
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                }else if(j==0){
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                }else{
                    dp[i][j]=min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
                }
            }
        }
        return dp[row-1][col-1];
    }
};