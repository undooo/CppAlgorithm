#include "stdc++.h"
using namespace std;
/*

有一个 m × n 的长方形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

这个岛被分割成一个个方格网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

岛上雨水较多，如果相邻小区的高度 小于或等于 当前小区的高度，雨水可以直接向北、南、东、西流向相邻小区。水可以从海洋附近的任何细胞流入海洋。

返回 网格坐标 result 的 2D列表 ，其中 result[i] = [ri, ci] 表示雨水可以从单元格 (ri, ci) 流向 太平洋和大西洋 。



*/

//第一个方法，自己想的，但是会超时，原因在于这种方法是对每个节点进行遍历
class Solution {
public:
    //可以从深度优先遍历考虑
    //设置两个判断，是否可以到达太平洋和是否可以到达大西洋
    //上下左右四个方向，若值小于等于当前值，则继续遍历，直到无法遍历或到达边界
    vector<int> direction{-1,0,1,0,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans{};
        if(heights.empty() || heights[0].empty()) return ans;
        int row=heights.size(),col=heights[0].size(),local_height=0;
        bool pacific,Atlantic;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                local_height=heights[i][j];
                vector<vector<int>> isVisited(row,vector<int>(col,0));
                pacific=Judge(heights,i,j,0,isVisited);
                vector<vector<int>> isVisited2(row,vector<int>(col,0));
                
                Atlantic=Judge(heights,i,j,1,isVisited2);
                //若二者都为真，则说明可以到达
                
                if(pacific && Atlantic){
                    vector<int> singal{i,j};
                    ans.push_back(singal);
                }
            }
        }
        return ans;
    }
    bool Judge(vector<vector<int>> & heights,int i,int j,int type,vector<vector<int>> & isVisited){
        //若已经到达了左上边界，则说明可以到达Pacific ocean
        if((i==0 || j==0) && type==0){
            return true;
        }else if((i==heights.size()-1 || j==heights[0].size()-1) && type==1){
            return true;
        }
        bool local_posi=false;
        
        //开始上下左右递归
        int x,y;
        for(int k=0;k<4;k++){
            x=i+direction[k];y=j+direction[k+1];
            //若移动后的海拔不大于当前的，则可以递归
            if(x>=0&&x<heights.size()&&y>=0&&y<heights[0].size()&&heights[x][y]<=heights[i][j]&&isVisited[x][y]==0){
                isVisited[x][y]=1;
                local_posi=(local_posi || Judge(heights,x,y,type,isVisited));
            }
        }
        return local_posi;

    }
};


