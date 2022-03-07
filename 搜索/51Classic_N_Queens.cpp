
#include "stdc++.h"
using namespace std;

/*
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

*/

class Solution {
public:


    //使用回溯法的思想
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        //若n为0的话，直接返回即可
        if (n==0) return ans;
        vector<bool> column(n,false),ldiag(2*n-1,false),rdiag(2*n-1,false);
        vector<string> singal(n,string(n,'.'));
        BackTracking(ans,singal,column,ldiag,rdiag,0,n);
        return ans;
    }

    //回溯过程
    void BackTracking(vector<vector<string>> &ans,vector<string> &singal,vector<bool> &column,vector<bool> &ldiag,vector<bool> &rdiag,int row,int n){
        //如果当前遍历的行已经与n相同，说明所有行已经找到了一个合适解
        if(row==n){
            ans.push_back(singal);
            return;
        }
        //对该行的所有点依次尝试
        for(int i=0;i<n;i++){
            //若已访问过，则说明该点不可取，跳过
            if(column[i] || ldiag[n-row+i-1] || rdiag[row+i]){
                continue;
            }
            //回溯
            singal[row][i]='Q';
            column[i]=ldiag[n-row+i-1]=rdiag[row+i]=1;
            BackTracking(ans,singal,column,ldiag,rdiag,row+1,n);
            singal[row][i]='.';
            
            column[i]=ldiag[n-row+i-1]=rdiag[row+i]=0;

        }


    }
};