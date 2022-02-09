#include<stdc++.h>
using namespace std;
/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/candy
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int candy(vector<int>& ratings) {

        //思路分析：
        //使用贪心算法，将每个孩子的糖果数都初始为1，之后进行两次遍历
        //第一次遍历判断当前孩子的评分是否比他左面的高，若是的话，则糖果数改为左面孩子+1
        //第二次遍历则判断是否比右面的孩子分数高
        //注意：有一个条件为得分高且当前糖果数低于相邻孩子，才改为临近孩子+1，在第一次的遍历中，不存在得分高且糖果数也高的情况
        //因此，在第二次遍历中，需要额外添加一个判断条件：除了得分高外，还要保证糖果数少
        int length=ratings.size();
        
        vector<int> CandyNum(length,1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                CandyNum[i]=CandyNum[i-1]+1;
            }
        }
        //这里要注意，ratings.size()是个数，因此在查看数组对应值的时候，要减一
        //而又因为要与右面元素比较，所以直接从倒数第二个孩子开始向前遍历，即ratings.size()-2
        for(int j=ratings.size()-2;j>=0;j--){
            if(ratings[j]>ratings[j+1]&&CandyNum[j]<=CandyNum[j+1])
                CandyNum[j]=CandyNum[j+1]+1;
        }
        return accumulate(CandyNum.begin(),CandyNum.end(),0);
    }
};

int main()
{
    return 0;
}