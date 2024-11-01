/*
 * @Author: dsaDadas11
 * @Date: 2024-10-17 13:54:51
 * @LastEditTime: 2024-10-17 13:56:04
 * @Description: go for it!
 */
/*
 解题思路：
 用分治，先处理后半的大的数，因为大的数进行1操作不会影响前半的小的数
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e4+7;
constexpr int M=2e3+7;
int n;
pair<int,int> b[M];
int a[M];
vector<pair<int,int> > ans;
void dfs(int l,int r)
{
	if(l>r) return;
	if(l==r)
	{
		auto [x,idx]=b[l];
		while(a[idx]<x)
		{
			ans.push_back({2,idx});
			a[idx]++;
		}
		return;
	}
	int mid=(l+r)>>1;
	int lx=mid,rx=mid-1;
	for(int i=lx;i<=r;i++)
	{
		auto [x,idx]=b[i];
		if(a[idx]==x)
		{
			lx++;
			continue;
		}
		a[idx]++;
		ans.push_back({2,idx});
	}
	auto [x,idx]=b[lx];
	while(a[idx]<x)
	{
		ans.push_back({1,a[idx]});
		for(int i=lx;i<=r;i++) a[b[i].second]++;
	}
	while(a[b[rx].second]==b[rx].first&&rx>=1) rx--;
	while(a[b[lx].second]==b[lx].first&&lx<=n) lx++;
	dfs(l,rx);
	dfs(lx,r);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].first;
		b[i].second=i;
	}
	sort(b+1,b+1+n);
	dfs(1,n);
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans)
	{
		cout<<x<<" "<<y<<endl;
	}
}
signed main()
{
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}