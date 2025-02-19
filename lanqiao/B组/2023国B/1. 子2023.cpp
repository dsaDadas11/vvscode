/*
 * @Author: HuangCe
 * @Date: 2025-02-18 15:12:54
 * @LastEditTime: 2025-02-18 15:15:19
 * @Description: go for it!
 */
/*
 解题思路：
 又是想不出来的 dp
 设状态：
 dp[0] 为 2的数量 dp[0]++
 dp[1] 为 20的数量 dp[1]+=dp[0]
 dp[2] 为 202的数量 dp[2]+=dp[1]
 dp[3] 为 2023的数量 dp[3]+=dp[2]
*/
#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  cout<<"5484660609"<<endl;
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
string s;
int dp[17];
void solve()
{
    for(int i=1;i<=2023;i++)
    {
        s+=to_string(i);
    }
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='2')
        {
            dp[0]++;
            dp[2]+=dp[1];
        }
        else if(s[i]=='0')
        {
            dp[1]+=dp[0];
        }
        else if(s[i]=='3')
        {
            dp[3]+=dp[2];
        }
    }
    cout<<dp[3]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/