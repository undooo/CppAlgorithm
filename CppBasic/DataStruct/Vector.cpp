#include <stdc++.h>
using namespace std;

void vector_func()
{   
//初始化vector存10个数字，且每位为1
    
    vector<int> arr(10,1);


//在vector的末尾添加一个元素   
    arr.push_back(1);
    
/*
    arr.size();     //返回vector的长度

    arr.clear();    //情况数组

    arr.empty();    //判断是否为空

    arr.begin();    //首地址迭代器

    arr.end();      //末未知元素下一位的迭代器

    arr.erase(p1);  //删除某迭代器位置的数字
*/
    
//迭代器
    vector<int>::iterator p1=arr.begin()++;
    
  //count
  vector<int> ex(10);
  //统计value为1的key有几个
  int ans=count(ex.begin(),ex.end(),1);
    //自定义统计方法
    count_if(ex.begin(),ex.end(),cmp);
   vector<int>::iterator p_arr;
    for(p_arr=arr.begin();p_arr !=arr.end();p_arr++)
    {
        printf("%d",*p_arr);
    }
        
}