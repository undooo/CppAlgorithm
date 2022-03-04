#include "stdc++.h"
using namespace std;
/*

有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量

*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //考虑遍历整个数组
        //从[i,j]开始，只要之间存在联系，便遍历j行所有元素并改为0，且对还有联系的行递归遍历
        int province=0;
        if(isConnected.empty() || isConnected[0].empty()) return 0;
        int row=isConnected.size(),col=isConnected[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isConnected[i][j]==1){
                    province++;
                    search_j(isConnected,j);
                }
            }
        }
        return province;
    }
    void search_j(vector<vector<int>> &isConnected,int j){
        int col=isConnected[0].size();
        for(int i=0;i<col;i++){
            if(isConnected[j][i]==1){
                isConnected[j][i]=0;
                search_j(isConnected,i);
            }
        }
        return;
    }
};