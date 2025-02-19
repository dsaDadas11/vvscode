/*
 * @Author: HuangCe
 * @Date: 2025-02-17 20:00:59
 * @LastEditTime: 2025-02-17 20:01:42
 * @Description: go for it!
 */
/*
 解题思路：
 感觉有点卡常，不优化就 t了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int n,k;
int a[N];
int pre[N],suf[N]; // 前后索引
int cnt[N];
bool vis[N];
void solve()
{
	cin>>n>>k;
	set<pair<int,int> > se;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		se.insert({a[i],i});
		pre[i]=i-1,suf[i]=i+1;
	}
	while(se.size()>n-k)
	{
		auto [val,idx]=*se.begin();
		se.erase(se.begin());
		if(cnt[idx])
		{
			a[idx]+=cnt[idx];
			cnt[idx]=0;
			se.insert({a[idx],idx});
			continue;
		}
		vis[idx]=1;
		int x=pre[idx],y=suf[idx];
		pre[y]=x;
		suf[x]=y;
		cnt[y]+=val,cnt[x]+=val;
	}
	while(se.size())
	{
		auto [val,idx]=*se.begin();
		se.erase(se.begin());
		a[idx]+=cnt[idx];
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		cout<<a[i]<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}