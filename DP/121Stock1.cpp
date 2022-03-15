#include"stdc++.h"
using namespace std;
/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //一次遍历实现
        //对于每一个点，最大利润都是当前价格减去之前的最低价格，因此只需保留当前最低价格，并用当前价格计算利润
        int MaxProfit=0,minprice=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minprice=min(minprice,prices[i]);
            MaxProfit=max(MaxProfit,prices[i]-minprice);
        }
        return MaxProfit;
    }
};