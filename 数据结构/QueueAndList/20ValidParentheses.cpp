#include"stdc++.h"
using namespace std;
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> quote;
        for(auto &str : s){
            if(str=='(' || str=='[' || str=='{'){
                quote.push(str);
                continue;
            }
            if(quote.empty()) return false;
            char qtop=quote.top();
            if((qtop=='(' && str==')' )||( qtop=='[' && str==']') || (qtop=='{' && str=='}')){
                quote.pop();
            }else{
                return false;
            }
        }
        return quote.empty();
    }
};