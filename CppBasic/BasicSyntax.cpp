#include<iostream>
#include<cstring>
using namespace std;



char str[10];
void function()
{   //清空一个数组
    //原理是将内存块中按位都改为给定字符（二进制），全部改为0则意味着清零，也可改为其他数字
    memset(str,0,sizeof(str));


    
}


//vector部分
#include<vector>
void vector_func()
{
    vector<int> arr;
    
    arr.push_back(1);//在vector的末尾添加一个元素
    arr.push_back(2);
    arr.push_back(3);
    /*arr.size();     //返回vector的长度

    arr.clear();    //情况数组

    arr.empty();    //判断是否为空

    arr.begin();    //首地址迭代器

    arr.end();      //末未知元素下一位的迭代器*/
    vector<int>::iterator p1=arr.begin()++;
    arr.erase(p1);  //删除某迭代器位置的数字
    cout<<arr[2]<<endl;
    /*
    //vector中的迭代器iterator（指针）,并将其指向一个vector的首地址
    vector<int>::iterator p_arr=arr.begin();
    for(p_arr=arr.begin();p_arr !=arr.end();p_arr++)
    {
        printf("%d",*p_arr);
    }*/
        
    


}

int main()
{
    
   
    system("pause");
    return 0;
}