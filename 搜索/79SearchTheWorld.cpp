#include"stdc++.h"
using namespace std;
/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。


*/
class Solution {
public:
    vector<int> directions{-1,0,1,0,-1};
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        int row=board.size(),col=board[0].size(),pos=0;
        vector<vector<bool>> isVisted(row,vector<bool>(col,false));
       
        bool result=false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                BackTracking(board,isVisted,i,j,word,pos,result);
                if(result==true) break;
            }
        }

        return result;
    }

    void BackTracking(vector<vector<char>>&board,vector<vector<bool>>&isVisted,int x,int y,string word,int pos,bool &result){
        //判断是否越界
        if(x<0 ||x>=board.size() ||y<0 ||y>=board[0].size()) return;
        //判断是否被访问过以及是否匹配
        if(isVisted[x][y] || result || board[x][y]!=word[pos]) return;
        //判断是否全部匹配
        if(pos==word.size()-1){
            result=true;
            return;
        } 
        int m,n;
     
        for(int i=0;i<4;i++){
            isVisted[x][y]=true;
            m=x+directions[i];n=y+directions[i+1];
            BackTracking(board,isVisted,m,n,word,pos+1,result);
            isVisted[x][y]=false;
        }
        
    


    }
};