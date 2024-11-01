/*
 * @Author: dsaDadas11
 * @Date: 2024-01-24 20:52:22
 * @LastEditTime: 2024-01-24 20:52:31
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define endl '\n'
using namespace std;
constexpr int N=1e5+7;
constexpr int M=1e3+7;
int n,q,a[M][M];
void solve()
{
	memset(a,0,sizeof a);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]+=x*y;
	}
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}
	while(q--)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		x1++;x2--;y1++;y2--;
		cout<<a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1]<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}