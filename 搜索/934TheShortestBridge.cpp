#include"stdc++.h"
using namespace std;
/*
在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）

现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。）

*/

class Solution {
public:
    vector<int> directions{-1,0,1,0,-1};
    //首先，dfs寻找到第一个岛，并在搜索的过程中将1改为2，原因在于区分第一个岛和第二个岛
    //之后，再通过bfs将第一个岛逐步向外扩展，直至找到岛2
    int shortestBridge(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();

        //设置一个队列，用于之后广度优先遍历
        queue<pair<int, int>> points;

        bool flag=false;
        for(int m=0;m<row;m++){
            if(flag==true) break;
            for(int n=0;n<col;n++){
                if(grid[m][n]==1){
                    dfs(grid,points,m,n);
                    flag=true;
                    break;
                }
            }
        }
        int step=0;
        //开始广度优先遍历，直至找到小岛
        while(!points.empty()){
            int q_size=points.size();
           
            
            //将这一层的所有点向外扩充一层，即搭一座桥
            step++;
            while(q_size--){
                 auto [x,y]=points.front();
                 points.pop();
                for(int i=0;i<4;i++){
                    int m=x+directions[i],n=y+directions[i+1];
                    //判断不同的情况
                    if(m<0 || m>=row || n<0 || n>=col){
                        continue;
                    }else{
                        //若下一个位置合法，则判断
                        if(grid[m][n]==2){
                            //等于2则说明碰到了本岛屿，跳过
                            continue;
                        }else if(grid[m][n]==0){
                            //若等于0，则说明碰到了海，将其加入points队列
                            points.push({m,n});
                            grid[m][n]=2;
                        }else{
                            //等于1则说明找到了岛2，返回结果即可
                            return step;
                        }
                    }
                }
            }
        }

    return 0;
    }

    void dfs(vector<vector <int>> &grid,queue<pair<int,int>> &points,int x,int y){
        if(x<0 ||x>=grid.size() || y<0 || y>=grid[0].size() ||grid[x][y]==2){
            return;
        }
        //等于0则说明遇到了海，将其放入quene中待取
        if(grid[x][y]==0){
            points.push({x,y});
            return;
        }
        grid[x][y]=2;
        for(int i=0;i<4;i++){
            int m=x+directions[i],n=y+directions[i+1];
            dfs(grid,points,m,n);
        }
        
    }
};