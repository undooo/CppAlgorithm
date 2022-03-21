#include"stdc++.h"
using namespace std;
/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。

*/

//新建一个栈，用于保存最小值
//每次插入元素时，判断是否小于当前最小值，若是则将其插入最小栈
//若等于，则将其同时退出两个栈
class MinStack {
private:
stack<int> My_stack,Min_stack;
int x=0;

public:
    MinStack() {

    }
    
    void push(int val) {
        My_stack.push(val);
        if(Min_stack.empty() || val<=Min_stack.top()){
            Min_stack.push(val);
        }
    }
    
    void pop() {
        if(My_stack.top() == Min_stack.top()){
            Min_stack.pop();
        }
        My_stack.pop();
    }
    
    int top() {
        return My_stack.top();
    }
    
    int getMin() {
        return Min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */