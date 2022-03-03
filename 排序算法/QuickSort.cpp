#include "stdc++.h"
using namespace std;


void QuickSort(vector<int>&nums,int l,int r)
{   
    if(l>=r){
        return;
    }
    //第一步、将第一个值放到最终位置
    int first=l,last=r,key=nums[first];
    while(first<last){
         //从右边开始遍历，只要比key大，就不用移动
        while(first<last && nums[last]>=key){
            last--;
        }
        nums[first]=nums[last];

        while(first<last && nums[first]<=key){
            first++;
        }
        nums[last]=nums[first];

    }
    nums[first]=key;
    //对剩余部分进行快排
    QuickSort(nums,l,last-1);
    QuickSort(nums,last+1,r);

}

int main()
{   
    vector<int> a={1,2,3,5,4};
    QuickSort(a,0,4);
    for(int x:a){
        cout<<x;
    }
    return 0;
}