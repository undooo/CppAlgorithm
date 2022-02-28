#include <stdc++.h>
using namespace std;
int arr[10];



bool cmp(vector<int>&a,vector<int> &b){
            return a[1]<b[1];
}

void SortFunction()
{

//sort的两种用法：

//第一种：升序/降序排序
    vector<int> arr(10);
    //升序排列
    sort(arr.begin(),arr.end());
    //降序
    sort(arr.begin(),arr.end(),greater<int>());

//第二种，自定义排序
    //例如，自定义为：按二维数组中每个数组的第二个数字大小升序排列
    vector<vector<int>> arr2;
    sort(arr2.begin(),arr2.end(),cmp);

//string利用反向迭代器实现逆转
    string str("cvicses");
    string s(str.rbegin(),str.rend());

}


void function()
{ 
//清空一个数组
    
    //原理是将内存块中按位都改为给定字符（二进制），全部改为0则意味着清零，也可改为其他数字
    memset(arr, 0, sizeof(arr));
    //同理，可以用这个函数将数组设置为无穷大
    const int INF = 0x3f3f3f3f;
    memset(arr, INF, sizeof(arr));
    //得到数组中的最小、最大值
    vector<int> arr1(10);
    min_element(arr1.begin(), arr1.end());
    max_element(arr1.begin(), arr1.end());

//求和
    //前两个参数为范围，第三个参数为累加的初始值
    accumulate(arr1.begin(), arr1.end(), 0);

//得到排序后第3小的元素
    nth_element(arr1.begin(), arr1.begin() + 2, arr1.end());

//交换两个变量
    swap(arr1[0], arr1[1]);
    
//反转
    reverse(arr1.begin(), arr1.end());

//得到独有元素的个数(原因在于unique返回的是末元素的下一位置)
    int newlength = unique(arr1.begin(), arr1.end()) - arr1.begin();
    
//去重
    unique(arr1.begin(), arr1.end());

//二分查找函数
    //若要把某个数字插入数组，则应该插入的下界位置的地址
    lower_bound(arr1.begin(), arr1.end(), 3);
    upper_bound(arr1.begin(), arr1.end(), 3);
}