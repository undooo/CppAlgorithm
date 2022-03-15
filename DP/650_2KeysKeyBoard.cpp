#include"stdc++.h"
using namespace std;
/*
最初记事本上只有一个字符 'A' 。你每次可以对这个记事本进行两种操作：

Copy All（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。
Paste（粘贴）：粘贴 上一次 复制的字符。
给你一个数字 n ，你需要使用最少的操作次数，在记事本上输出 恰好 n 个 'A' 。返回能够打印出 n 个 'A' 的最少操作次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/2-keys-keyboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //复制粘贴是倍增操作，与之前的加减不同
    int minSteps(int n) {
        vector<int> dp(n+1,0);
        int mid=sqrt(n);
        for(int i=2;i<=n;i++){
            //仅考虑复制单个字符的情况下，扩展到n需要n步
            dp[i]=i;
            //考虑复制其他长度的情况
            for(int j=2;j<=mid;j++){
                //若可以整除，则说明i长度可以由j生成，且操作次数与i/j相同
                if(i%j==0){
                    dp[i]=dp[j]+dp[i/j];
                    break;
                }
            }
        }
        return dp[n];
    }
};