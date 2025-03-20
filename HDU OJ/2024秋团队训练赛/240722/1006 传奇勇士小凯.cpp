/*
 * @Author: dsaDadas11
 * @Date: 2024-07-22 19:03:04
 * @LastEditTime: 2024-07-22 19:05:27
 * @Description: go for it!
 */
/*
  解题思路：先算在一个点的的天数公式，得到1/p
  因此，我们只需要找一条路径使1/p的值相加最大
  值得注意的点：1.分式应该随时化简
              2.分式的加法
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int n,to,tt;
int p[N];
int u,v,fenz,fenm;
vector<int> g[N];
void dfs(int fa,int now,int tzi,int tmu)
{
	// 走到最后的点
	int len=g[now].size();
	if(len==1&&g[now][0]==fa)
	{
		if(fenz*tmu<fenm*tzi)
		{
			fenz=tzi,fenm=tmu;
		}
	}
	for(int i=0;i<len;i++)
	{
		to=g[now][i];
		if(to==fa) continue;
		int t1=tzi*p[to]+tmu;
		int t2=tmu*p[to];
		tt=gcd(t1,t2);
		dfs(now,to,t1/tt,t2/tt);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) cin>>p[i];
	fenz=1,fenm=p[1];
	dfs(0,1,fenz,fenm);
	fenz*=15;
	tt=gcd(fenz,fenm);
	cout<<fenz/tt<<"/"<<fenm/tt<<endl;
	for(int i=1;i<=n;i++) g[i].clear();
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}