#include<stdc++.h>
/*
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。


*/




bool cmp(vector<int>&a,vector<int> &b){
            return a[1]<b[1];
        }

class Solution {
public:
   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       
        
        sort(intervals.begin(),intervals.end(),cmp);
        int total=0,prev=intervals[0][1],length=intervals.size();
        for(int i=1;i<length;i++){
            if(intervals[i][0]<prev){
                total++;
            }
            else{
                prev=intervals[i][1];
            }
        }
        return total;
    }
};


int main(){
    return 0;
}