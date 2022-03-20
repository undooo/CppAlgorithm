#include"stdc++.h"
using namespace std;
/*
给你一个由数字和运算符组成的字符串 expression ，
按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。
*/

class Solution {
public:
    //分治法
    //不同的运算组合其实就是算以当前运算符最优，将两边都求出结果后做相应运算即可
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for(int i=0;i<expression.size();i++){
            char c=expression[i];
            //如果当前字符为运算符，则开始分治
            if(c=='+' || c=='-' || c=='*'){
                //求出左面所有可能的运算结果
                vector<int> left=diffWaysToCompute(expression.substr(0,i));
                //同理求出右面结果
                vector<int> right=diffWaysToCompute(expression.substr(i+1));
                //对所有可能结果进行运算
                for(const int i:left){
                    for(const int j:right){
                        switch(c){
                            case '+':
                                ans.push_back(i+j);
                                break;
                            case '-':
                                ans.push_back(i-j);
                                break;
                            case '*':
                                ans.push_back(i*j);
                                break;

                        }
                    }
                }
            }
        }
        if (ans.empty()) ans.push_back(stoi(expression));
        return ans;
    }
};