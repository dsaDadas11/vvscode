/*
 * @Author: dsaDadas11
 * @Date: 2025-10-11 19:27:41
 * @LastEditTime: 2025-10-11 19:27:47
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int gcd(int x,int y)
{
    return x?gcd(y%x,x):y;
}
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int minn=min({a,b,c});
    int maxn=max({a,b,c});
    int gg=gcd(minn,maxn);
    cout<<minn/gg<<'/'<<maxn/gg<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}