#include <stdc++.h>
using namespace std;

void MapFunctino(){

//pair
    //用于将两种任意的数据结构结合起来
    pair<string,int> pr("小明",180);


//map
    map<string,int> height{{"小红",1},{"小黑",170}};
    height["小白"]=180;
    height.insert(pr);
}