#include"stdc++.h"
using namespace std;
/*
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

*/
//第一种思路，广度优先遍历
class Solution {
public:
    //广度优先遍历
    vector<int> dir{-1,0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty()) return{{}};
        int row=mat.size(),col=mat[0].size();
        //设置数组判断是否遍历过
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        //设置最短路径数组
        vector<vector<int>> dis(row,vector<int>(col,100000));
        //设置队列
        queue<pair<int,int>> qList;
        //将所有的0点距离初始化为0，并加入队列
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    visited[i][j]=1;
                    dis[i][j]=0;
                    qList.push({i,j});
                }
            }
        }

        //开始广度优先遍历
        while(!qList.empty()){
            int qSize=qList.size();
            while(qSize--){
                auto [x,y]=qList.front();
                qList.pop();
                for(int k=0;k<4;k++){
                    int m=x+dir[k],n=y+dir[k+1];
                    if(m>=0 &&m<row && n>=0 && n<col && !visited[m][n]){
                        dis[m][n]=dis[x][y]+1;
                        visited[m][n]=true;
                        qList.push({m,n});
                    }
                }
            }
        }
        return dis;

    }
};