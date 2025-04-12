/*
 * @Author: dsaDadas11
 * @Date: 2025-03-30 16:01:58
 * @LastEditTime: 2025-03-30 16:02:06
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y,z;
void solve()
{
    cin>>x;
    int ans=-1;
    for(int i=0;i<=30;i++)
    {
        for(int j=0;j<=30;j++)
        {
            y=(1<<i)|(1<<j);
            z=x^y;
            if(x+y>z&&x+z>y&&z+y>x&&y<x) ans=y;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}