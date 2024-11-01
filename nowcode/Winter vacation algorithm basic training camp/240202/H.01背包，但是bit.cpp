/*
 * @Author: dsaDadas11
 * @Date: 2024-02-04 19:06:37
 * @LastEditTime: 2024-02-04 19:06:43
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int v[N],w[N];
void solve()
{
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>v[i]>>w[i];
	}
	int ans=0;
	for(int i=0;i<=32;i++)
	{
		if((m>>i)&1||i==0)
		{
			int x=(1ll<<i)-1;
			int res=(m|x);
			int sum=0;
			for(int j=0;j<n;j++)
			{
				if((w[j]>>i)&1&&i!=0) continue;
				if((res|w[j])==res) sum+=v[j];
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}