#include"stdc++.h"
using namespace std;
/*
给定一个长度为 n 的整数数组 arr ，它表示在 [0, n - 1] 范围内的整数的排列。

我们将 arr 分割成若干 块 (即分区)，并对每个块单独排序。将它们连接起来后，使得连接的结果和按升序排序后的原数组相同。

返回数组能分成的最多块数量。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-chunks-to-make-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    //判断当前最大值是否等于数组位置，若是，则说明可以在此进行一次分割
    int maxChunksToSorted(vector<int>& arr) {

        int ans=0,max=arr[0];
        for(int i=0;i<arr.size();i++){
            max=arr[i]>max?arr[i]:max;
            if(i==max) ans++;
        }
        return ans;

    }
};