/*
 * @Author: dsaDadas11
 * @Date: 2025-03-31 16:47:05
 * @LastEditTime: 2025-03-31 16:47:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int x[N],r[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }

    map<int,int> mx,vis;
    int d;
    for(int i=1;i<=n;i++)
    {
        for(int j=x[i]-r[i];j<=x[i]+r[i];j++)
        {
            d=sqrt(r[i]*r[i]-(x[i]-j)*(x[i]-j));
            mx[j]=max(mx[j],d);
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=x[i]-r[i];j<=x[i]+r[i];j++)
        {
            if(vis[j]) continue;
            vis[j]=1;
            ans+=2*mx[j]+1;
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