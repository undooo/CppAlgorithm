#include "stdc++.h"
using namespace std;
/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

*/

//该题为困难题，思路为双指针滑动窗口

class Solution {
public:
    string minWindow(string s, string t) {
        //本题采用滑动窗口的思路实现
        //首先，创建两个数组，来判断各个字符是否出现以及出现的次数
        vector<int> char_num(128,0);
        vector<bool> flag(128,false);
        for(int i=0;i<t.size();i++){
            flag[t[i]]=1;
            char_num[t[i]]++;
        }
        
        //创立几个变量储存相关数据
        int l=0,min_size=s.size()+1,cnt=0,min_l=0;
        
        //将右边框逐步向右推进，并更改相关字符数据
        for(int r=0;r<s.size();r++){
            //若当前字符存在，则进行之后操作
            if(flag[s[r]]){
                if(--char_num[s[r]]>=0){
                    cnt++;
                }
                //当此时cnt已经与t长度相同时，说明已包含所有字母,则开始右移左指标
                while(cnt==t.size()){
                    //若当前窗口更小，则更新数据
                    if(r-l+1<min_size){
                        min_l=l;
                        min_size=r-l+1;
                    }

                    if(flag[s[l]] && ++char_num[s[l]]>0){
                        cnt--;
                    }
                    l++;
                }
            }
        }
        return min_size>s.size()?"":s.substr(min_l,min_size);
    }
};