#include"stdc++.h"
using namespace std;
/*
判断两个字符串包含的字符是否完全相同。
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(auto i:count){
            if(i) return false;
        }
        return true;
    }
};