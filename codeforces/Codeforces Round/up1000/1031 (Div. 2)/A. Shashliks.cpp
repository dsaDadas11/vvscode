/*
 * @Author: dsaDadas11
 * @Date: 2025-08-05 19:42:45
 * @LastEditTime: 2025-08-05 19:42:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int k;
int calc(int a,int b,int x,int y)
{
    int res=max(k-a+x,0LL);
    int ans=res/x;
    int tmp=k-ans*x;
    ans+=max(tmp-b+y,0LL)/y;
    return ans;
}
int a,b,x,y;
void solve()
{
    cin>>k>>a>>b>>x>>y;
    cout<<max(calc(a,b,x,y),calc(b,a,y,x))<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}