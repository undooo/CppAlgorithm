#include "stdc++.h"
using namespace std;
/*
给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


//初始做法及思路

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        //记录最长字符串,flag用于记录是否找到过匹配字符串
        int max_serial=0,flag=0;
        
        for(int num_dic=0;num_dic<dictionary.size();num_dic++){
        //首先，建立两个指针，分别指向s的开头和dic中每个元素的开头
        int poi_s=0,poi_dic=0;
        
        //若s小于dic中的字符串，则必定不匹配，直接跳过
        if(s.size()<dictionary[num_dic].size()) continue;
       
        //只要s还未遍历完，就循环遍历
        while(poi_s<=s.size()){
           //若此时poi_dic已经到达了dic的最后一位的下一位，则说明全部匹配成功
       
            if(poi_dic==dictionary[num_dic].size()){
            
            //需要额外判断当初始最大位置仍为0，但是匹配长度小于0号位字符串长度的情况
            if(max_serial==0 && flag==0 &&num_dic!=0){
                max_serial=num_dic;
                flag=1;
                
            }

            
            if(dictionary[num_dic].size()>dictionary[max_serial].size()){
                max_serial=num_dic;
                flag=1;
            }

            if(dictionary[num_dic].size()==dictionary[max_serial].size()){
                max_serial=dictionary[num_dic]>dictionary[max_serial]?max_serial:num_dic;
                flag=1;
                
            }
            break;
            }
            if(s[poi_s]==dictionary[num_dic][poi_dic]){
                poi_s++;poi_dic++;
            }
            else{
                poi_s++;
            }
        }
        }
        return flag==1?dictionary[max_serial]:"";
    }
};


//优化思路
//优化点：直接先将字符串数组按照要求排好顺序，以此为基础，只要从前往后挨个判断即可，不需要考虑大小问题
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string& a, string& b)
        {
            if(a.length() == b.length()) return a < b;
            return a.length() > b.length();
        });
        int n = s.length();
        for(auto& ss : dictionary){
            int m = ss.length();
            if(m > n) continue;
            int i = 0, j = 0;
            while(i < n && j < m){
                if(s[i] == ss[j]) j++;
                i++;
                if(j == m) return ss;
            }
        }
        return "";
    }
};