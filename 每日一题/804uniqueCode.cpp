#include"stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> codelist={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> anslist;
        if(words.size()==0) return 0;
        //讲每个字符串翻译为代码
        for(int i=0;i<words.size();i++){
            string thiscode;
            for(int j=0;j<words[i].size();j++){
                thiscode+=codelist[words[i][j]-'a'];
            }
            anslist.emplace(thiscode);
        }



        return anslist.size();
    }
};