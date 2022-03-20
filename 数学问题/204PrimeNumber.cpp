#include"stdc++.h"
using namespace std;
/*
找出小于n的所有素数的个数
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> judge(n,true);
        int ans=0;
        //判断n前的所有数字，采用数字一次性储存所有的倍数
        for(int i=2;i<n;i++){
            //若当前为false，则说明是个质数，并将其所有倍数设置为false
            if(judge[i]==true){
                ans++;
                for(int j=2;j*i<n;j++){
                    judge[j*i]=false;
                }
            }
        }
        return ans;

    }
};