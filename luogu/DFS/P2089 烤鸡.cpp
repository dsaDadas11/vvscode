/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 22:41:28
 * @LastEditTime: 2024-01-17 22:41:35
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n,ans;
int a[17],vis[17][5],b[10000][17];
void dfs(int x,int sum)
{
	if(x==11)
	{
		if(sum==n)
		{
			ans++;
			for(int i=1;i<=10;i++)
			{
				b[ans][i]=a[i];
			}
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(vis[x][i]) continue;
		a[x]=i;
		vis[x][i]=1;
		dfs(x+1,sum+i);
		vis[x][i]=0;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n<10||n>30)
	{
		cout<<"0"<<endl;
		return 0;
	}
	dfs(1,0);
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
	{
		for(int j=1;j<=10;j++)
		{
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}