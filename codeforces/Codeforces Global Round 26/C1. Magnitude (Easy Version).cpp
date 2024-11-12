/*
 * @Author: dsaDadas11
 * @Date: 2024-11-07 12:33:24
 * @LastEditTime: 2024-11-07 14:06:53
 * @Description: go for it!
 */
/*
 解题思路：
 取操作2的次数只为1次，因为当前缀为负的最大的时候才需要取绝对值，然后后面的数只需要加上就可以
 例如：2 -5 -6 -7 9  ，我们只需将 2 -5 -6 -7 的值取绝对值，然后加9就是答案
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n;
int a[N];
int sum[N],suf[N];
void solve()
{
	cin>>n;
	for(int i=0;i<=n+5;i++) sum[i]=suf[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,abs(sum[i])+suf[i+1]);
	}
	cout<<maxn<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}