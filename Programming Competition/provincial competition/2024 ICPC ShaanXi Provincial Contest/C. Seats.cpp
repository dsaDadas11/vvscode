/*
 * @Author: dsaDadas11
 * @Date: 2024-09-02 19:43:56
 * @LastEditTime: 2024-09-02 19:47:38
 * @Description: go for it!
 */
/*
 解题思路：
 i连到a[i]的位置，然后跑一遍拓扑排序，将最长路、环的顶点总数相加就是答案
 前置知识拓扑排序：
 拓扑排序是在dag(有向无环图)中将入度为0的节点放进队列
 拓扑排序时环不会进入队列，所以可以判断图是否含有环，并且算出环的顶点个数
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,ans;
int a[N];
int ind[N];
int dep[N];
vector<int> g[N];
queue<int> q;
void top_sort()
{
	for(int i=1;i<=2*n;i++)
	{
		if(ind[i]==0) q.push(i);
	}
	int cnt=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		cnt++;
		/*
		因为每一个顶点只有一个出边，当now>n时就是终点了
		但是呢，会有很多这样的不连通图组成一个森林
		举个例子：
		1->2->3->7
		5->6->8
		这两个图互不联通并且都可以最优化，因此两个图的最长边都能加
		一开始没想到这点...
		*/
		if(now>n)
		{
			ans+=dep[now];
			continue;
		}
		for(auto it:g[now])
		{
			ind[it]--;
			if(ind[it]==0) q.push(it);
			dep[it]=max(dep[it],dep[now]+1);
		}
	}
	ans+=2*n-cnt;
	cout<<ans<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[i].push_back(a[i]);
		ind[a[i]]++;
	}
	top_sort();
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}