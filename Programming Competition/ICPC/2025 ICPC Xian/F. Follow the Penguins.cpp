/*
 * @Author: dsaDadas11
 * @Date: 2025-10-21 16:21:43
 * @LastEditTime: 2025-10-21 16:23:31
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=5e9;
struct op
{
    int val;
    int u,v;
    bool operator<(const op&that) const
    {
        if (val != that.val) return val < that.val;
        if (u != that.u) return u < that.u;
        return v < that.v;
    }
};
int n;
int t[N],a[N];
int dir[N],ans[N];
multiset<op> se;
map<int,vector<op> > mp1,mp2;
int vis1[N],vis2[N];
int dt;
// 处理 mp2
void calc2(int x)
{
    if(vis2[x]||!mp2.count(x)) return;
    vis2[x]=1;

    for(auto [val,u,v]:mp2[x])
    {
        se.insert({val+dt,u,v});
    }
}
// 处理 mp1
void calc1(int x)
{
    if(vis1[x]||!mp1.count(x)) return;
    vis1[x]=1;

    for(auto [val,u,v]:mp1[x])
    {
        if(!se.count({val,u,v})) continue;
        se.erase({val,u,v});
        se.insert({2*val-dt,u,v});
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]*=2;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[t[i]]) dir[i]=1;
        else if(a[i]>a[t[i]]) dir[i]=-1;
    }

    for(int i=1;i<=n;i++)
    {
        // i追 t[i]
        if(dir[i]*dir[t[i]]<0) // 会相遇
        {
            se.insert({abs(a[i]-a[t[i]])/2,i,t[i]});
            mp1[t[i]].push_back({abs(a[i]-a[t[i]])/2,i,t[i]});
        }
        else if(dir[i]*dir[t[i]]==0)
        {
            se.insert({abs(a[i]-a[t[i]]),i,t[i]});
        }
        else // 不相遇
        {
            mp2[t[i]].push_back({abs(a[i]-a[t[i]]),i,t[i]});
        }
    }

    while(!se.empty())
    {
        auto [val,u,v]=*se.begin();
        se.erase(se.begin());

        val-=dt;
        dt+=val;
        ans[u]=dt;

        dir[u]=0;
        calc2(u);
        calc1(u);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}