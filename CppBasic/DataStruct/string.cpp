#include "stdc++.h"
using namespace std;


void StringFunction()
{   string a;
    //1.substr
    //传入两个参数，第一个为起始位置(从0开始)，第二个为截取字符的数目
    a.substr(1,7);
    //对于字符串与数字的相互转换，可以使用sstream
    double x;
    string str;
    stringstream ss;
    //string to num
    cin>>str;
    ss<<str;
    ss>>x;
    //num to string
    cin>>x;
    ss<<x;
    ss>>str;




}