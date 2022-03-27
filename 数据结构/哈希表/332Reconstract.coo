#include"stdc++.h"
using namespace std;
/*
给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-itinerary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:

    //对于字典排序最小的问题，可以通过multipset存储目的地，set会自动将其从小到大排序
    //设置一个哈希表，值为多重集合
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> hash;
        vector<string> ans;
        stack<string> s;
        s.push("JFK");
        //记录所有的行程
        for(auto & flight:tickets){
            hash[flight[0]].insert(flight[1]);
        }
        //搜索
        while(!s.empty()){
            //若此时哈希表对应的值无目标，则说明找到了目的地
            string place=s.top();
            if(hash[place].empty()){
                ans.push_back(place);
                s.pop();
            }else{
                //若仍然存在节点，则将第一个(以此保证字典最小)放入栈  
                s.push(*hash[place].begin());
                //删除节点
                hash[place].erase(hash[place].begin());
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};