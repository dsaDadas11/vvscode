/*
 * @Author: dsaDadas11
 * @Date: 2025-07-20 17:19:08
 * @LastEditTime: 2025-07-20 17:19:15
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
void solve()
{
    cin>>n>>m>>k;
    vector<int> vis(k+1),have(k+1);
    int x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        vis[x]=1;
    }
    int ans=0;
    map<pair<int,int>,int> cnt;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(vis[x]&&vis[y]) ans++;
        else if(vis[x]) have[y]++;
        else if(vis[y]) have[x]++;
        else
        {
            if(x<y) swap(x,y);
            if(x==y) have[x]++;
            else cnt[{x,y}]++;
        }
    }
    // 认识两个有关联的人
    int res=0;
    for(auto [x,y]:cnt)
    {
        auto [a,b]=x;
        res=max(res,have[a]+have[b]+y);
    }
    // 认识两个随意的人
    vector<int> v;
    for(int i=1;i<=k;i++)
    {
        if(vis[i]) continue;
        v.push_back(have[i]);
    }
    v.push_back(0);
    v.push_back(0);
    sort(v.begin(),v.end(),greater<int>());
    res=max(res,v[0]+v[1]);
    cout<<ans+res<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}