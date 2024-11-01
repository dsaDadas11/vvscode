/*
 * @Author: dsaDadas11
 * @Date: 2024-04-23 20:16:13
 * @LastEditTime: 2024-04-23 20:16:19
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int l,n,ans;
int row[7]; // 每一行的总和
int col[7]; // 每一列的总和
void dfs(int x,int y)
{
	if(y==n)
	{
		x++;
		y=1;
	}
	if(x==n)
	{
		int sumr=0,sumc=0;
		// 左上角的n-1矩阵，画个图就能明白
		for(int i=1;i<n;i++)
		{
			sumc+=l-row[i];
			sumr+=l-col[i];
		}
		if(sumr<=l&&sumc<=l) ans++;
		return;
	}
	for(int i=0;i<=l-row[x]&&i<=l-col[y];i++)
	{
		row[x]+=i;
		col[y]+=i;
		dfs(x,y+1);
		row[x]-=i;
		col[y]-=i;
	}
}
void solve()
{
	cin>>l>>n;
	dfs(1,1);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}