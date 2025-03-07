/*
 * @Author: dsaDadas11
 * @Date: 2025-03-04 18:34:30
 * @LastEditTime: 2025-03-04 18:34:44
 * @Description: go for it!
 */
// URL: https://www.lanqiao.cn/problems/2186/learning/
#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  cout<<"379187662194355221"<<endl;
  return 0;
}
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dp[2023][11];
void solve()
{
    dp[0][0]=1;
    for(int i=1;i<=2022;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(i<j) break;
            dp[i][j]=dp[i-j][j]+dp[i-j][j-1];
        }
    }
    cout<<dp[2022][10]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/