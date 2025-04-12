/*
 * @Author: dsaDadas11
 * @Date: 2025-04-06 11:13:55
 * @LastEditTime: 2025-04-06 11:14:16
 * @Description: go for it!
 */
#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  cout<<"14";
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
int month[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void solve()
{
    int ans=0;
    for(int i=1;i<=12;i++)
    {
        for(int j=1;j<=month[i];j++)
        {
            string s=" 2022";
            if(i<10) s.push_back('0');
            s+=to_string(i);
            if(j<10) s.push_back('0');
            s+=to_string(j);
            int len=s.size()-1;
            bool ok=0;
            for(int k=1;k<=len-2;k++)
            {
                if(s[k]+1==s[k+1]&&s[k]+2==s[k+2]) ok=1;
            }
            if(ok) ans++;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/