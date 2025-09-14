/*
 * @Author: dsaDadas11
 * @Date: 2025-08-19 19:44:46
 * @LastEditTime: 2025-08-19 19:44:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=5e3+5;
int n;
int d[M],vis[M];
char s[M][M];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='1') d[i]++;
        }
    }

    int a=1,b=-1,c=-1;
    for(int i=2;i<=n;i++)
    {
        if(d[i]>d[a]) a=i;
    }
    if(d[a]==n-1) return cout<<"NOT FOUND"<<endl,void();

    for(int i=1;i<=n;i++)
    {
        if(s[i][a]=='1')
        {
            vis[i]=1;
            b=i;
        }
        d[i]=0;
    }
    if(b==-1) return cout<<"NOT FOUND"<<endl,void();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vis[i]&&vis[j]&&s[i][j]=='1') d[i]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]>d[b]) b=i;
    }

    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        if(s[i][b]=='1') vis[i]=1,c=i;
        d[i]=0;
    }
    if(c==-1) return cout<<"NOT FOUND"<<endl,void();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vis[i]&&vis[j]&&s[i][j]=='1') d[i]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]>d[c]) c=i;
    }
    cout<<a<<' '<<b<<' '<<c<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}