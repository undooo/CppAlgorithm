#include "stdc++.h"
using namespace std;

void InsertionSort(vector<int>&nums)
{   int n=nums.size();
    for(int i=1;i<n;i++){
        for(int j=i;j>0 &&nums[j]<nums[j-1];j--){
            swap(nums[j],nums[j-1]);
        }
    }
    return;
}

int main()
{   
    vector<int> a={1,2,3,5,4};
    InsertionSort(a);
    for(int x:a){
        cout<<x;
    }
    return 0;
}