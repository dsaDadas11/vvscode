/*
 * @Author: dsaDadas11
 * @Date: 2025-09-05 12:13:55
 * @LastEditTime: 2025-09-05 12:14:02
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int fa[N],sz[N];
int find_fa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}
void merge_set(int x,int y)
{
    int fax=find_fa(x),fay=find_fa(y);
    if(fax==fay) return;
    sz[fay]+=sz[fax];
    fa[fax]=fay;
}
int n,m;
vector<int> g[N];
int u[N],v[N];
int cnt[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i,sz[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i];
        merge_set(u[i],v[i]);
    }

    int ans=0;
    for(int i=1;i<=m;i++)
    {
        cnt[find_fa(u[i])]++;
    }

    for(int i=1;i<=n;i++)
    {
        if(find_fa(i)!=i) continue;
        int len=sz[i];
        int sum=cnt[i];
        // cout<<len<<' '<<sum<<endl;
        int res=len*(len-1)/2-sum;
        ans+=res;
    }

    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        if(find_fa(i)!=i) continue;
        v.push_back(sz[i]);
    }
    sort(v.begin(),v.end());
    if(ans==0) ans=v[0]*v[1];
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}