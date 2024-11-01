/*
 * @Author: dsaDadas11
 * @Date: 2024-03-29 23:01:00
 * @LastEditTime: 2024-03-29 23:01:06
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
char a[M][M];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]=='1')
			{
				int sum=0;
				cout<<fixed<<setprecision(1)<<1.0*i-0.5<<' ';
				int cnt=0;
				while(a[i][j]=='1')
				{
					sum+=j-0.5;
					j++;
					cnt++;
				}
				cout<<fixed<<setprecision(1)<<1.0*sum/cnt+0.5<<' ';
				cout<<cnt<<' '<<"1"<<endl;
			}
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