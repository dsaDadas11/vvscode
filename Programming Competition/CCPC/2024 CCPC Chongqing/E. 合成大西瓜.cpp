/*
 * @Author: dsaDadas11
 * @Date: 2025-01-12 19:46:42
 * @LastEditTime: 2025-01-12 19:57:03
 * @Description: go for it!
 */
/*
 解题思路：
 只有度数为 1的节点需要找次小值，大于 1的节点取最大值
 然后两者再取大的即可（具体原理还没搞懂）
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,m;
int a[N];
int d[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		d[u]++,d[v]++;
	}
	int ans=-1e18;
	int mx1=-1e18,mx2=-1e18;
	for(int i=1;i<=n;i++)
	{
		if(d[i]==1)
		{
			if(mx1<a[i])
			{
				mx2=mx1;
				mx1=a[i];
			}
			else mx2=max(mx2,a[i]);
		}
		else
		{
			ans=max(ans,a[i]);
		}
	}
	cout<<max(ans,mx2)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}