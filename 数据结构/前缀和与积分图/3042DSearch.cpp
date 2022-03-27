#include"stdc++.h"
using namespace std;
/*
给定一个二维矩阵 matrix，以下类型的多个请求：

计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
实现 NumMatrix 类：

NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class NumMatrix {
private:

    vector<vector<int>> psnm2D;
public:
    NumMatrix(vector<vector<int>>& matrix):psnm2D(matrix.size(),vector<int>(matrix[0].size(),0)) {

        for(int i=0;i<psnm2D.size();i++){
            for(int j=0;j<psnm2D[0].size();j++){
                int up=i-1>=0?psnm2D[i-1][j]:0;
                int left=j-1>=0?psnm2D[i][j-1]:0;
                int ul=(i-1>=0 && j-1>=0)?psnm2D[i-1][j-1]:0;
                psnm2D[i][j]=matrix[i][j]+up+left-ul;
            }
        }
    }
    
    int sumRegion(int m, int n, int i, int j) {
        int up=m-1>=0?psnm2D[m-1][j]:0;
        int left=n-1>=0?psnm2D[i][n-1]:0;
        int ul=(m-1>=0 && n-1>=0)?psnm2D[m-1][n-1]:0;
        return psnm2D[i][j]-up-left+ul;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */