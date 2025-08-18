/*
 * @Author: dsaDadas11
 * @Date: 2024-05-18 17:16:24
 * @LastEditTime: 2024-05-18 17:22:58
 * @Description: go for it!
 */
/*
解题思路：
1.bfs算出每个点离两人和终点的最短路(bfs记得剪枝，不然爆内存)
2.如果两个人与终点没有最短路返回-1
3.int temp=dte[tar]*te+dfe[tar]*fe;
  ans=min(ans,min(temp,dte[i]*te+dfe[i]*fe+dtar[i]*(te+fe-s)));
  遍历每个可能达到的点，算它们走一起和最初的temp哪个更小
4.这道题不建议用memset，因为不确定dis的值，后续不好判断
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=4e4+7;
constexpr int M=2e3+7;
int te,fe,s; // 移动消耗值
int t,f,tar,n;
int u,v;
int ans=1e18;
int dte[N],dfe[N],dtar[N];
bool vis1[N],vis2[N],vis3[N];
vector<int> g[N];
queue<int> q;
void bfs()
{
	q.push(t);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(vis1[u]) continue;
		vis1[u]=1;
		for(int i=0;i<(int)g[u].size();i++)
		{
			v=g[u][i];
			if(vis1[v]) continue;
			q.push(v);
			dte[v]=min(dte[v],dte[u]+1);
		}
	}
	while(!q.empty()) q.pop();
	q.push(f);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(vis2[u]) continue;
		vis2[u]=1;
		for(int i=0;i<(int)g[u].size();i++)
		{
			v=g[u][i];
			if(vis2[v]) continue;
			q.push(v);
			dfe[v]=min(dfe[v],dfe[u]+1);
		}
	}
	while(!q.empty()) q.pop();
	q.push(tar);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(vis3[u]) continue;
		vis3[u]=1;
		for(int i=0;i<(int)g[u].size();i++)
		{
			v=g[u][i];
			if(vis3[v]) continue;
			q.push(v);
			dtar[v]=min(dtar[v],dtar[u]+1);
		}
	}
}
void solve()
{
	cin>>te>>fe>>s;
	cin>>t>>f>>tar>>n;
//	memset(dte,0x3f,sizeof dte);
//	memset(dfe,0x3f,sizeof dfe);
//	memset(dtar,0x3f,sizeof dtar);
	for(int i=1;i<=tar;i++)
	{
		dte[i]=2e9;
		dfe[i]=2e9;
		dtar[i]=2e9;
	}
	dte[t]=0,dfe[f]=0,dtar[tar]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();
	if(dte[tar]==2e9||dfe[tar]==2e9)
	{
		cout<<"-1"<<endl;
		return;
	}
	int temp=dte[tar]*te+dfe[tar]*fe;
	for(int i=1;i<=tar;i++)
	{
		if(dte[i]==2e9||dfe[i]==2e9||dtar[i]==2e9) continue;
		ans=min(ans,min(temp,dte[i]*te+dfe[i]*fe+dtar[i]*(te+fe-s)));
	}
	if(ans==1e18) cout<<"-1"<<endl;
	else cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}