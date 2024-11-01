/*
 * @Author: dsaDadas11
 * @Date: 2024-04-23 11:12:55
 * @LastEditTime: 2024-04-23 11:14:08
 * @Description: go for it!
 */
// dfs
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n=5,ans;
int a[17][17];
bool check()
{
	//对角线
	int dui1=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][i]) dui1++;
	}
	if(dui1==5||dui1==0) return 0;
	int dui3=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][n-i+1]) dui3++;
	}
	if(dui3==5||dui3==0) return 0;
	// 行、列
	for(int i=1;i<=n;i++)
	{
		int cnt1=0,cnt3=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]) cnt1++;
			if(a[j][i]) cnt3++;
		}
		if(cnt1==5||cnt1==0||cnt3==5||cnt3==0) return 0;
	}
	return 1;
}
void dfs(int x,int y,int cnt)
{
	if(cnt>13) return;
	if(check()&&cnt==13)
	{
		ans++;
		return;
	}
	if(y==n+1)
	{
		y=1;
		x++;
	}
	if(x==n+1) return;
	a[x][y]=1;
	dfs(x,y+1,cnt+1);
	a[x][y]=0;
	dfs(x,y+1,cnt);
}
signed main()
{
	dfs(1,1,0);
	cout<<ans<<endl;
	return 0;
}

// 二进制枚举
/*
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n=5,ans;
int a[17][17];
bool check(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x&1) a[i][j]=1;
			else a[i][j]=0;
			// a[i][j]=x%2;
			sum+=a[i][j];
			x>>=1;
		}
	}
	if(sum!=13) return 0;
	//对角线
	int dui1=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][i]) dui1++;
	}
	if(dui1==5||dui1==0) return 0;
	int dui3=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][n-i+1]) dui3++;
	}
	if(dui3==5||dui3==0) return 0;
	// 行、列
	for(int i=1;i<=n;i++)
	{
		int cnt1=0,cnt3=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]) cnt1++;
			if(a[j][i]) cnt3++;
		}
		if(cnt1==5||cnt1==0||cnt3==5||cnt3==0) return 0;
	}
	return 1;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// 二进制枚举(优化复杂度：直接从13位1开始枚举到25位1)
	for(int i=(1<<13)-1;i<(1<<25);i++)
	{
		if(check(i)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
*/