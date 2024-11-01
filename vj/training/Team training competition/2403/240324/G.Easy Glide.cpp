/*
 * @Author: dsaDadas11
 * @Date: 2024-04-09 19:16:26
 * @LastEditTime: 2024-04-09 19:44:39
 * @Description: go for it!
 */
//朴素版
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
bool st[N];
double dist[N],g[N][N];
int n,v1,v2,sx,sy,tx,ty;
struct op
{
	int x,y;
}p[N];
double dist1(op a,op b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))/v1;
}
double dist2(op a,op b)
{
	double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	if(d<=3*v2) return d/v2;
	else return (d-3*v2)/v1+3;
}
void dijkstra()
{
	for(int i=0;i<=n;i++) dist[i]=2e9;
	dist[0]=0;
	for(int i=0;i<=n;i++)
	{
		int t=-1;
		for(int j=0;j<=n;j++)
		{
			if(!st[j]&&(t==-1||dist[t]>dist[j]))
			{
				t=j;
			}
		}
		st[t]=1;
		if(t==n) break;
		for(int j=0;j<=n;j++)
		{
			if(g[t][j]==-1) continue;
			if(dist[j]>dist[t]+g[t][j])
			{
				dist[j]=dist[t]+g[t][j];
			}
		}
	}
}
void solve()
{
	memset(g,-1,sizeof g);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	cin>>sx>>sy>>tx>>ty;
	cin>>v1>>v2;
	++n;
	p[0].x=sx,p[0].y=sy;
	p[n].x=tx,p[n].y=ty;
	for(int i=1;i<=n;i++)
	{
		g[0][i]=dist1(p[0],p[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			g[i][j]=dist2(p[i],p[j]);
		}
	}
	dijkstra();
	cout<<fixed<<setprecision(8)<<dist[n]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
/*
堆优化版：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
bool st[N];
double dist[N],g[N][N];
int n,v1,v2,sx,sy,tx,ty;
struct op
{
	int x,y;
}p[N];
struct node
{
	double dis;
	int u;
	bool operator>(const node &that) const
	{
		return dis>that.dis;
	}
};
double dist1(op a,op b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))/v1;
}
double dist2(op a,op b)
{
	double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	if(d<=3*v2) return d/v2;
	else return (d-3*v2)/v1+3;
}
void dijkstra()
{
	for(int i=0;i<=n;i++) dist[i]=2e9;
	dist[0]=0;
	priority_queue<node,vector<node>,greater<node> > q;
	q.push({0,0});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int u=t.u;
		if(st[u]) continue;
		st[u]=1;
		for(int i=0;i<=n;i++)
		{
			if(dist[i]>dist[u]+g[u][i])
			{
				dist[i]=dist[u]+g[u][i];
				q.push({dist[i],i});
			}
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	cin>>sx>>sy>>tx>>ty;
	cin>>v1>>v2;
	++n;
	p[0].x=sx,p[0].y=sy;
	p[n].x=tx,p[n].y=ty;
	for(int i=1;i<=n;i++)
	{
		g[0][i]=dist1(p[0],p[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			g[i][j]=dist2(p[i],p[j]);
		}
	}
	dijkstra();
	cout<<fixed<<setprecision(8)<<dist[n]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/