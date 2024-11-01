/*
 * @Author: dsaDadas11
 * @Date: 2024-03-28 18:46:53
 * @LastEditTime: 2024-03-28 18:46:57
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[37][607];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n*3;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n*3;j+=3)
		{
			if(a[i][j]+a[i][j+1]+a[i][j+2]<=90) cout<<"1";
			else cout<<"0";
		}
		cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}