#include "stdc++.h"
using namespace std;
/*

给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 


*/

class Solution {
public:
    //巧妙地将4个方向用5个数字表示出来
    vector<int> directions={-1,0,1,0,-1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //首先要判断是否为空，不然后面取size操作会报错
        if(grid.empty() || grid[0].empty()) return 0;
        //使用深度优先遍历，递归得到最大面积
        int max_area=0,row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                max_area=max(max_area,dfs(grid,i,j));
            }
        }
        return max_area;
        
    }
    int dfs(vector<vector<int>> & grid,int x,int y){
        if(grid[x][y]==0) return 0;
        int m,n,area=1;
        grid[x][y]=0;
        for(int i=0;i<4;i++){
            m=x+directions[i];n=y+directions[i+1];
            if(m>=0 &&m<grid.size()&&n>=0&&n<grid[0].size()){
                area+=dfs(grid,m,n);
            }
        }
        return area;
    }
};