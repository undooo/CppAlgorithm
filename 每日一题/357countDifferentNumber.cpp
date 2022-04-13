#include"stdc++.h"
using namespace std;
/*
给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10n 。
*/
class Solution {
public:
    //动态规划
    //可以考虑当现在有n位的时候，n-1位可以构成的数字位a[i-1]
    //后面的都不同，第n位可取的数目为9-后面已有数字数目
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        //压缩空间，只需要三个int字节
        int first=1,second=10,third=0;
        for(int i=2;i<=n;i++){
            third=second+(second-first)*(10-(i-1));
            first=second;
            second=third;
        }
        return third;
    }
};