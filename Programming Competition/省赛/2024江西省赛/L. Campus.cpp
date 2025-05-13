/*
 * @Author: dsaDadas11
 * @Date: 2025-04-21 20:22:41
 * @LastEditTime: 2025-04-21 20:31:37
 * @Description: go for it!
 */
/*
 解题思路：
 想到了前面求大门到其他点的最短路，后面想根据线段进行差分，但是发现很难实现
 看到题解 遍历 1到 t，每个时间都判断哪些大门开放，然后存到一个 map里，即 map<大门,位置> mp
 然后遍历大门开放的情况，根据开放的大门更新每个点的最短路
 大门开放情况最多 15种 (不是 2^15种)，然后每次遍历位置
 时间复杂度大概为 n*k*k (1e5*15*15还是随便过的)，
 这种处理线段的方法值得学习
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define pll pair<int,int>
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
constexpr int inf=1e16;
int n,m,k,t;
vector<pll> g[N];
int a[N];
int pos[17],hasp[17];
pll p[17];
int ans[N];
void dijikstra(int s,vector<int>& dist)
{
	dist[s]=0;
	priority_queue<pll,vector<pll>,greater<> > pq;
	pq.push({0,s});
	vector<bool> vis(n+5);
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto [w,v]:g[u])
		{
			if(dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
    
}
void solve()
{
	cin>>n>>m>>k>>t;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=k;i++)
	{
		cin>>pos[i];
		hasp[i]=pos[i];
		cin>>p[i].first>>p[i].second;
	}
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	
	// 每个大门到其他点的最短路
    vector<vector<int> > dist(k+3,vector<int>(n+3,inf));
	for(int i=1;i<=k;i++)
	{
		dijikstra(hasp[i],dist[i]);
	}

    map<vector<int>,vector<int> > mp;
	for(int i=1;i<=t;i++)
    {
        vector<int> tmp(k+1);
        for(int j=1;j<=k;j++)
        {
            if(p[j].first<=i&&i<=p[j].second)
            {
                tmp[j]=1;
            }
        }
        mp[tmp].push_back(i);
    }

	for(auto [tmp,op]:mp)
    {
        vector<int> d(n+1,inf);
        bool ok=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(tmp[j]) d[i]=min(d[i],dist[j][i]),ok=1;
            }
        }
        if(!ok)
        {
            for(auto i:op) ans[i]=-1;
            continue;
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i]*d[i];
        }
        for(auto i:op) ans[i]=sum;
    }

    for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}