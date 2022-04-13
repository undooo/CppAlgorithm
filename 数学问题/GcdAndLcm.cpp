#include"stdc++.h"
using namespace std;


//辗转相除法原理
int gcd(int m,int n){
    return n?gcd(n,m%n):m;
}

//最小公倍数=两数相乘/最大公因数

int lcm(int a,int b){
    return a*b/gcd(a,b);
}


