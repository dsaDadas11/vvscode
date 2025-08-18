/*
 * @Author: dsaDadas11
 * @Date: 2025-07-22 15:56:59
 * @LastEditTime: 2025-07-22 15:57:06
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,s;
int dx[N],dy[N],x[N],y[N];
void solve()
{
    cin>>n>>s;
    map<pair<int,int>,int> mp;
    for(int i=1;i<=n;i++)
    {
        cin>>dx[i]>>dy[i]>>x[i]>>y[i];
        mp[{dx[i],dy[i]}]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(y[i]==-x[i]+s)
        {
            if(mp[{1,-1}]||mp[{-1,1}]) ans++;
        }
        if(y[i]==x[i])
        {
            if(mp[{1,1}]||mp[{-1,-1}]) ans++;
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