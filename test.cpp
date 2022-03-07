#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<vector<int>> dp(105,vector<int>(100005,0));
vector<int> a;
int main()
{   //读取相关信息
    //动态规划，从第一个砝码开始，依次判断是否会有更多的重量
    int num,singal_weight,sum;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>singal_weight;
        a.push_back(singal_weight);
        sum+=singal_weight;
    }
    dp[0][a[0]]=1;
    //从第二个砝码开始判断
    for(int i=1;i<num;i++){
        
        //复制上一组的状况
        for(int j=0;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
        }
        //自己本身的重量肯定可以求出来
        dp[i][a[i]]=1;
        //知道了这些之后，开始判断之前的值与当前砝码能判断的重量
        for(int k=0;k<=sum;k++){
            if(dp[i][k]==1){
                //第一种，求和
             
                dp[i][k+a[i]]=1;
                //第二种，求差
                
                dp[i][abs(k-a[i])]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=sum;i++){
        ans=dp[num-1][i]==1?ans+1:ans;
    
    }
    cout<<ans;
    system("pause");
    return 0;
}