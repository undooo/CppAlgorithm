#include"stdc++.h"
using namespace std;
/*
给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/isomorphic-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> first_appear_1(256,0);
        vector<int> first_appear_2(256,0);
      
        for(int i=0;i<s.size();i++){
            if(first_appear_1[s[i]]!=first_appear_2[t[i]]) return false;
            first_appear_1[s[i]]=first_appear_2[t[i]]=i+1;
        }
        return true;
    }
};