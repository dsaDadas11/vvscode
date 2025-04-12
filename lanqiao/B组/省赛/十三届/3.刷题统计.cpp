/*
 * @Author: dsaDadas11
 * @Date: 2025-04-07 17:30:06
 * @LastEditTime: 2025-04-07 17:30:17
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b,n;
void solve()
{
    cin>>a>>b>>n;
    int ans=0;
    int sum5=a*5,sum2=b*2;
    ans+=(n/(sum5+sum2))*7;
    n%=(sum5+sum2);
    int x=1;
    while(n>0)
    {
        if(x==6||x==7) n-=b;
        else n-=a;
        ans++;
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