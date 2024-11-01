/*
* @Author: dsaDadas11
* @Date: 2024-10-20 19:51:33
 * @LastEditTime: 2024-10-30 13:25:17
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
int a[N],b[N];
pair<int,int> p[N];
map<int,int> nxt; // 存这个点的下一个充电站
vector<int> v[N];
// 存离这个站点最近的充电站的电量 优先使用
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
// 存没有充电站或者遍历完这个点之后没有充电站了
queue<int> q;
// 存这个充电站后面还有几个一样的充电站，用来判断是q 还是 pq
map<int,int> mp;
// 标记哪一些有充电站
bool vis[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	sort(p+1,p+1+m);
	for(int i=1;i<=m;i++)
	{
		vis[p[i].second]=1;
		mp[p[i].second]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			q.push(a[i]);
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		v[p[i].second].push_back(p[i].first);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)v[i].size()-1;j++)
		{
			nxt[v[i][j]]=v[i][j+1];
		}
	}
	
	set<int> se;
	for(int i=1;i<=m;i++)
	{
		if(!se.count(p[i].second))
		{
			pq.push(p[i]);
			se.insert(p[i].second);
		}
	}
	
	int ans=0;
	// 遍历每一个充电站
	for(int st=1;st<=m;st++)
	{
		int d=p[st].first-p[st-1].first;
		
		// 先用离这位置近的充电站站点
		while(!pq.empty()&&d>0)
		{
			int x=pq.top().first;
			int pos=pq.top().second;
			if(a[pos]==0)
			{
				pq.pop();
				continue;
			}
			if(d<a[pos])
			{
				pq.pop();
				ans+=d;
				pq.push({x,pos});
				a[pos]-=d;
				d=0;
			}
			else
			{
				ans+=a[pos];
				d-=a[pos];
				a[pos]=0;
				pq.pop();
			}
		}
		
		// 再用q里的
		while(d>0&&!q.empty())
		{
			int val=q.front();
			if(d<val)
			{
				ans+=d;
				q.pop();
				q.push(val-d);
				d=0;
			}
			else
			{
				ans+=val;
				d-=val;
				q.pop();
			}
		}
		if(d>0) break;
		
		// 走到了这一个充电站，开始充电
		a[p[st].second]=b[p[st].second];
		if(mp[p[st].second]>0) mp[p[st].second]--;
		if(mp[p[st].second]==0)
		{
			q.push(a[p[st].second]);
			if(!pq.empty()&&pq.top()==p[st]) pq.pop();
		}
		else
		{
			if(!pq.empty()&&pq.top()==p[st]) pq.pop();
			pq.push({nxt[p[st].first],p[st].second});
		}
	}
	
	while(!q.empty())
	{
		ans+=q.front();
		q.pop();
	}
	cout<<ans<<endl;
	
	for(int i=0;i<=n+5;i++)
	{
		vis[i]=0;
		v[i].clear();
	}
	while(!pq.empty()) pq.pop();
	while(!q.empty()) q.pop();
	mp.clear();
	nxt.clear();
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
/*
2
3 1
3 3 3
8 1
2 2
5 2
1 2
2 1

ans: 12 9

1
2 3
2 3
1 1
3 1
6 1

ans: 10

1
4 4
2 3 4 5
2 1
3 2
8 1
10 2

ans: 22
*/