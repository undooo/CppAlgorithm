#include"stdc++.h"
using namespace std;
/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int nsize=matrix.size();
        for(int i=0;i<=(nsize/2)-1;i++){
            for(int j=i;j<nsize-(i+1);j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[nsize-1-j][i];
                matrix[nsize-1-j][i]=matrix[nsize-1-i][nsize-1-j];
                matrix[nsize-1-i][nsize-1-j]=matrix[j][nsize-1-i];
                matrix[j][nsize-1-i]=temp;
            }
        }
        
    }
};