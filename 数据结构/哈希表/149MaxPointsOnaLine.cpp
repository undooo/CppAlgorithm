#include"stdc++.h"
using namespace std;
/*
给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //建立一个哈希表，保存不同斜率有的点数
        unordered_map<double,int> Linemap;
        //same_y表示无斜率的部分（因为斜率通过dx/dy表示）
        int maxPoints=0,same=1,same_y=1;
        
        for(int i=0;i<points.size();i++){
            same=1;same_y=1;
            for(int j=i+1;j<points.size();j++){
                //判断是否重点或者无斜率
                if(points[j][1]==points[i][1]){
                    //无斜率
                    same_y++;
                    if(points[j][0]==points[i][0]){
                        same++;
                    }

                }else{
                    //计算斜率
                    double dx=points[j][0]-points[i][0],dy=points[j][1]-points[i][1];
                    double dxdy=dx/dy;
                    Linemap[dxdy]++;
                }
            }
            //判断无斜率的情况是否更多
            maxPoints=max(maxPoints,same_y);
            for(auto & num:Linemap){
                maxPoints=max(maxPoints,same+num.second);
            }
            Linemap.clear();
        }
        return maxPoints;
    }
};