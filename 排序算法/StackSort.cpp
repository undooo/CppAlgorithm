#include"stdc++.h"
using namespace std;

//栈排序
stack<int> StackSort(stack<int> &R)
{
    stack<int> S;
    int t=R.top();
    R.pop();
    while(!R.empty()){
        if(S.empty() || S.top()<=t){
            S.push(t);
            t=R.pop();
        }
    }
    //最后还有一个t没有被放入
    S.push(t);
}