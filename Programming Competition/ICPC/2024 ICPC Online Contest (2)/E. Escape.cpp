/*
 * @Author: dsaDadas11
 * @Date: 2024-09-23 13:52:19
 * @LastEditTime: 2024-09-23 18:13:44
 * @Description: go for it!
 */
/*
 解题思路：
 我们预处理一下robot到小于等于d路径的步数，然后再和Sneaker到当前步数比较即可，
 如果不小于就不能选择这个节点，还有，数组都是用滚动数组来写的，注意不要出错
 当u==n时，我们就判断当前的步数是不是小于之前记录的步数，如果是那就更新pre数组和ans数组
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
constexpr int inf=1e18;
int n,m,d,k;
int s[N],ans[N];
vector<int> g[N];
int pre[N][2];
//   Sneaker     robot
int dis1[N][2],dis2[N][2];
bool vis1[N][2],vis2[N][2];
struct op
{
	int u,step;
	bool operator<(const op&a) const
	{
		return step>a.step;
	}
};
// 预处理robot能走的位置
void bfs()
{
	priority_queue<op> pq;
	for(int i=1;i<=k;i++)
	{
		dis2[s[i]][0]=0;
		vis2[s[i]][0]=1;
		pq.push({s[i],0});
	}
	while(!pq.empty())
	{
		auto [u,step]=pq.top();
		pq.pop();
		if(step>=d) continue;
		int now=step&1,nxt=now^1;
		vis2[u][now]=0;
		for(auto v:g[u])
		{
			if(dis2[v][nxt]>dis2[u][now]+1)
			{
				dis2[v][nxt]=dis2[u][now]+1;
				if(vis2[v][nxt]) continue;
				vis2[v][nxt]=1;
				pq.push({v,dis2[v][nxt]});
			}
		}
	}
}
// 找答案
int find_ans()
{
	priority_queue<op> pq;
	// 从 1 开始
	dis1[1][0]=0;
	pre[1][0]=-1;
	vis1[1][0]=1;
	pq.push({1,0});
	int len=inf; // 最短路径
	while(!pq.empty())
	{
		auto [u,step]=pq.top();
		pq.pop();
		int now=step&1,nxt=now^1;
		vis1[u][now]=0;
		if(u==n)
		{
			int cnt=0;
			while(u!=-1)
			{
				u=pre[u][now];
				cnt++;
				now^=1;
			}
			if(cnt<len)
			{
				len=cnt;
				now=step&1;
				u=n,cnt=0;
				while(u!=-1)
				{
					ans[++cnt]=u;
					u=pre[u][now];
					now^=1;
				}
			}
			continue;
		}
		for(auto v:g[u])
		{
			if(dis1[v][nxt]>dis1[u][now]+1&&dis1[u][now]+1<dis2[v][nxt])
			{
				pre[v][nxt]=u;
				dis1[v][nxt]=dis1[u][now]+1;
				if(vis1[v][nxt]) continue;
				vis1[v][nxt]=1;
				pq.push({v,dis1[v][nxt]});
			}
		}
	}
	if(len!=inf) return len;
	return 0;
}
void solve()
{
	cin>>n>>m>>d;
	for(int i=0;i<=n;i++)
	{
		g[i].clear();
		pre[i][0]=pre[i][1]=-1;
		vis1[i][0]=vis1[i][1]=vis2[i][0]=vis2[i][1]=0;
		dis1[i][0]=dis1[i][1]=dis2[i][0]=dis2[i][1]=inf;
	}
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>k;
	for(int i=1;i<=k;i++) cin>>s[i];
	bfs();
	int len=find_ans();
	if(len==0) cout<<"-1"<<endl;
	else
	{
		cout<<len-1<<endl;
		for(int i=len;i>=1;i--)
		{
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}