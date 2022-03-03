#include <stdc++.h>
using namespace std;

int main(){

//pair
    //用于将两种任意的数据结构结合起来
    pair<string,int> pr("ming",180);
    //取出pair的对象
    string name=pr.first;
    int hei=pr.second;

//map
    //map会自动根据key的大小来进行排序
    map<string,int> height{{"red",1},{"black",170}};
    //1.直接赋值
    height["white"]=180;
    //insert一对pair
    height.insert(pr);
    //若已经存在该key，则再次insert不会更改原来的值
    height.insert(make_pair("li",160));
    height.insert(make_pair("li",170));
    height["white"]=170;
    map<string,int>::iterator it=height.begin();
    for(  ;it!=height.end();it++){
        printf("%s->%d\n",it->first.c_str(),it->second);
    }
    //查看该key是否存在，可以用count
    cout<<height.count("red")<<endl;
    //若还要知道该key的值，则使用find，返回的是迭代器（若没有找到，则返回end迭代器）
    map<string,int>::iterator search;
    search=height.find("red");
    cout<< search->second<<endl;
    return 0;
}