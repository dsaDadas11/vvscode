/*
 * @Author: dsaDadas11
 * @Date: 2025-03-05 18:52:17
 * @LastEditTime: 2025-03-05 20:26:13
 * @Description: go for it!
 */

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
double dist[157][157];
pair<int,int> p[157];
string s[157];
int fa[157];
double di[157],dd[157];
int findfa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=findfa(fa[x]);
}
void merge(int x,int y)
{
	int fax=findfa(x);
	int fay=findfa(y);
	fa[fax]=fay;
}
double calc(int i,int j)
{
    auto [xx1,yy1]=p[i];
    auto [xx2,yy2]=p[j];
    double d=sqrt((xx2-xx1)*(xx2-xx1)+(yy2-yy1)*(yy2-yy1));
    return d;
}
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) fa[i]=i;
    int x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        p[i]={x,y};
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) dist[i][j]=0;
            else dist[i][j]=1e16;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]=' '+s[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i][j]=='0') continue;
            merge(i,j);
            dist[i][j]=calc(i,j);
        }
    }
    floyd();
    for(int i=1;i<=n;i++)
    {
        x=findfa(i);
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            y=findfa(j);
            if(x!=y) continue;
            di[i]=max(di[i],dist[i][j]);
        }
        dd[x]=max(dd[x],di[i]);
    }
    double ans=1e16;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            x=findfa(i);
            y=findfa(j);
            if(x==y) continue;
            ans=min(ans,max({di[i]+di[j]+calc(i,j),dd[x],dd[y]}));
        }
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}