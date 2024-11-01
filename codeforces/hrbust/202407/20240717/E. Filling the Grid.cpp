/*
 * @Author: dsaDadas11
 * @Date: 2024-07-17 17:34:45
 * @LastEditTime: 2024-07-17 17:36:02
 * @Description: go for it!
 */
/*
 这道题的hack点在于判断是否存在这个矩阵，判断完之后找点就行了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
bool vis[M][M];
int r[M],c[M];
int n,m;
int quickpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>r[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=r[i];j++)
		{
			vis[i][j]=1;
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=c[j];i++)
		{
			vis[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int num=0;
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j]) num++;
			if(!vis[i][j]) break;
		}
		if(num!=r[i])
		{
			cout<<"0"<<endl;
			return;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int num=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i][j]) num++;
			if(!vis[i][j]) break;
		}
		if(num!=c[j])
		{
			cout<<"0"<<endl;
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=r[i]+2;j<=m;j++)
		{
			if(!vis[i][j]&&c[j]+1<i)
			{
				cnt++;
			}
		}
	}
	cout<<quickpow(2,cnt)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}