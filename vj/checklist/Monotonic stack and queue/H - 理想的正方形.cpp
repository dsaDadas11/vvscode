/*
 * @Author: dsaDadas11
 * @Date: 2024-03-08 13:46:07
 * @LastEditTime: 2024-03-08 13:46:13
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
deque<int> q1,q2; //max min
int a[M][M],x[M][M],X[M][M],y[M][M],Y[M][M];
int n,m,k,ans=1e18;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++) // 行
	{
		while(!q1.empty()) q1.pop_back();
		while(!q2.empty()) q2.pop_back();
		for(int j=1;j<=m;j++) // 列
		{
			while(!q1.empty()&&a[i][j]>=a[i][q1.back()]) q1.pop_back();
			q1.push_back(j);
			while(!q2.empty()&&a[i][j]<=a[i][q2.back()]) q2.pop_back();
			q2.push_back(j);
			while(j-q1.front()+1>k) q1.pop_front();
			while(j-q2.front()+1>k) q2.pop_front();
			if(j>=k)
			{
				X[i][j-k+1]=a[i][q1.front()];
				x[i][j-k+1]=a[i][q2.front()];
			}
		}
	}
	for(int i=1;i<=m-k+1;i++) // 列
	{
		while(!q1.empty()) q1.pop_back();
		while(!q2.empty()) q2.pop_back();
		for(int j=1;j<=n;j++) // 行
		{
			while(!q1.empty()&&X[j][i]>=X[q1.back()][i]) q1.pop_back();
			q1.push_back(j);
			while(!q2.empty()&&x[j][i]<=x[q2.back()][i]) q2.pop_back();
			q2.push_back(j);
			while(j-q1.front()+1>k) q1.pop_front();
			while(j-q2.front()+1>k) q2.pop_front();
			if(j>=k)
			{
				Y[j-k+1][i]=X[q1.front()][i];
				y[j-k+1][i]=x[q2.front()][i];
			}
		}
	}
	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=1;j<=m-k+1;j++)
		{
			ans=min(ans,Y[i][j]-y[i][j]);
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