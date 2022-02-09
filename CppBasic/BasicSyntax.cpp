#include<stdc++.h>
using namespace std;



int str[10];
void function()
{   //清空一个数组
    //原理是将内存块中按位都改为给定字符（二进制），全部改为0则意味着清零，也可改为其他数字
    memset(str,0,sizeof(str));
    //同理，可以用这个函数将数组设置为无穷大
    const int INF=0x3f3f3f3f;

    memset(str,INF,sizeof(str));
    //得到数组中的最小、最大值
    vector <int> arr1(10);
    min_element(arr1.begin(),arr1.end());
    max_element(arr1.begin(),arr1.end());
    
    //求和
    //前两个参数为范围，第三个参数为累加的初始值
    accumulate(arr1.begin(),arr1.end(),0);
    //得到排序后第3小的元素
    nth_element(arr1.begin(),arr1.begin()+2,arr1.end());

    //交换两个变量
    swap(arr1[0],arr1[1]);
    //反转
    reverse(arr1.begin(),arr1.end());

    //得到独有元素的个数(原因在于unique返回的是末元素的下一位置)
    int newlength=unique(arr1.begin(),arr1.end())-arr1.begin();
    
    //去重
    unique(arr1.begin(),arr1.end());
    
    //二分查找函数
    //若要把某个数字插入数组，则应该插入的下界位置的地址
    lower_bound(arr1.begin(),arr1.end(),3);
    upper_bound(arr1.begin(),arr1.end(),3);
    
}
//数据结构

void DataStruct()
{
    //pair对，用于将两种任意的数据结构结合起来
    pair<string,int> pr("小明",180);


    //map
    map<string,int> height{{"小红",1},{"小黑",170}};
    height["小白"]=180;
    height.insert(pr);

    //bitset 位集合

}
//vector部分

void vector_func()
{   //初始化vector存10个数字，且每位为1
    vector<int> arr(10,1);
    
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
    
    //vector中的迭代器iterator（指针）,并将其指向一个vector的首地址
    vector<int>::iterator p_arr=arr.begin();
    for(p_arr=arr.begin();p_arr !=arr.end();p_arr++)
    {
        printf("%d",*p_arr);
    }
        
}

int main()
{
    vector<int> a = {1,3,3,4,5,6,6,7};
    vector<int>::iterator it_1 = a.begin();
    vector<int>::iterator it_2 = a.end();
    int upper;

    upper=upper_bound(a.begin(),a.end(),3)-a.begin();
    
    cout<<upper;
    return 0;
}