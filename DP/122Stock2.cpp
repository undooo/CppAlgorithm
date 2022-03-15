#include"stdc++.h"
using namespace std;
/*
给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。

在每一天，你可能会决定购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以购买它，然后在 同一天 出售。
返回 你能获得的 最大 利润 。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //dp
    //由于可以无限次的买卖股票，对于每一天而言，只有两种状态：
    //持有股票或者不持有股票
    //且每天状态只与前一天有关，因此可以压缩空间
    int maxProfit(vector<int>& prices) {
        int length=prices.size();
        //设置持有和不持有股票的初始值
        int dp0=0,dp1=-prices[0];
        for(int i=0;i<length;i++){
            dp0=max(dp0,dp1+prices[i]);
            dp1=max(dp0-prices[i],dp1);
        }
        return dp0;
    }
};