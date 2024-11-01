/*
* @Author: dsaDadas11
* @Date: 2024-10-20 21:02:43
* @LastEditTime: 2024-10-30 13:02:43
* @Description: go for it!
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
// 第a[i]位成员在忙
int a[N];
// 拉入会议的人
bool vis[N];
bool vis1[N];
int d[N];
queue<int> q;
vector<int> g[N];
vector<vector<int> > ans;
void bfs()
{
	for(int i=1;i<=n;i++)
	{
		if(vis1[i]==0)
		{
			q.push(i);
			vis[i]=1;
			break;
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis1[u]) continue;
		vector<int> vv;
		vv.push_back(u);
		bool flag=0;
		for(auto v:g[u])
		{
			if(vis[v]) continue;
			vis[v]=1;
			vv.push_back(v);
			q.push(v);
			flag=1;
		}
		if(flag) ans.push_back(vv);
	}
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		vis1[a[i]]=1;
	}
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++,d[v]++;
	}
	bfs();
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
	cout<<(int)ans.size()<<endl;
	for(int i=0;i<(int)ans.size();i++)
	{
		for(int j=0;j<(int)ans[i].size();j++)
		{
			if(j==0) cout<<ans[i][j]<<' ';
			else if(j==1)
			{
				cout<<(int)ans[i].size()-1<<' ';
				cout<<ans[i][j]<<' ';
			}
			else cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
/*
4 5 2
3 4
1 2
1 3
2 3
3 4
2 4


4 5 3
2 4 3
1 2
1 3
2 3
3 4
2 4

*/