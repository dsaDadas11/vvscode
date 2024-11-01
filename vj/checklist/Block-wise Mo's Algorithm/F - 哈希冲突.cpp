/*
 * @Author: dsaDadas11
 * @Date: 2024-01-18 13:17:22
 * @LastEditTime: 2024-01-18 13:17:31
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int a[N],dp[M][M];
void solve()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=sqrt(n);j++)
			dp[j][i%j]+=a[i];
	while(m--)
	{
		char cmd; cin>>cmd;
		int x,y; cin>>x>>y;
		if(cmd=='A')
		{
			if(x<=sqrt(n)) cout<<dp[x][y]<<endl;
			else
			{
				int ans=0;
				for(int i=y;i<=n;i+=x) ans+=a[i];
				cout<<ans<<endl;
			}
		}
		else
		{
			for(int i=1;i<=sqrt(n);i++)
				dp[i][x%i]+=y-a[x];
			a[x]=y;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}