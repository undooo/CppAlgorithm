#include"stdc++.h"
using namespace std;
/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指在第 i 天之后，才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。

*/

class Solution {
public:

    //维护一个单调栈
    //从左往右遍历，若当前p的温度大于栈顶的温度，则将栈顶q出栈，q的等待天数为p-q
    //若p小于等于栈顶的温度，则将其放入栈
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mono_stack;
        int fate=temperatures.size();
        vector<int> ans(fate);
        for(int i=0;i<fate;i++){
            //将每个元素与单调栈比较
            while(!mono_stack.empty()){
                int pre_index=mono_stack.top();
                if(temperatures[i]<=temperatures[pre_index]) break;
                mono_stack.pop();
                ans[pre_index]=i-pre_index;
            }
            mono_stack.push(i);
        }
        return ans;
    }
};