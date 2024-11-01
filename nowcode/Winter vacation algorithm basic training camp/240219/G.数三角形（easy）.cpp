/*
 * @Author: dsaDadas11
 * @Date: 2024-02-19 18:58:17
 * @LastEditTime: 2024-02-19 18:58:23
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
char mp[M][M];
int pre[M][M];
void solve()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='*') pre[i][j]=pre[i][j-1]+1;
			else pre[i][j]=pre[i][j-1];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
            if(mp[i][j]!='*') continue;
			for(int k=1;k<=n-i+1;k++) //高度
			{
				if(j-k<1||j+k>m) continue;
                if(mp[i+k][j-k]!='*'||mp[i+k][j+k]!='*') break;
				if(pre[i+k][j+k]-pre[i+k][j-k-1]==2*k+1) ans++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}