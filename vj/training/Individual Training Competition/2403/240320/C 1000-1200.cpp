/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-03-22 22:05:31
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int nx[10]={1,-1,0,0,1,-1,1,-1};
int ny[10]={0,0,1,-1,1,-1,-1,1};
char s[M][M];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>s[i][j];
		}
	}
	int ans=0;
	bool yi=0,er=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='1')
			{
				ans++;
				continue;
			}
			yi=1;
			for(int k=0;k<8;k++)
			{
				int x=i+nx[k];
				int y=j+ny[k];
				if(x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='0')
				{
					er=1;
				}
			}
		}
	}
	if(!yi) ans-=2;
	else if(!er) ans-=1;
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}