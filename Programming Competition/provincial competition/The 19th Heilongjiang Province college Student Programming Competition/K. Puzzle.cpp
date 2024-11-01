/*
 * @Author: dsaDadas11
 * @Date: 2024-05-14 20:05:42
 * @LastEditTime: 2024-05-14 20:19:12
 * @Description: go for it!
 */
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define buff ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=2e5+7;
int a[10];
char c[10];
int b[10];
char d[10];
int vis[10];
int gg[10];
set<int> ss;
int ans=0;
void judge()
{
	gg[1]=b[1];
	gg[2]=b[2];
	gg[3]=b[3];
	gg[4]=b[4];
	ans=0;
	for(int i=1;i<=3;i++)
	{
		if(d[i]=='*')
		{
			int temp=1;
			for(int j=i+1;j<=3;j++)
			{
				if(d[j]!='*') break;
				temp*=gg[j+1];;
			}
			gg[i]=gg[i]*gg[i+1]*temp;
		}
	}
	ans=gg[1];
	for(int i=1;i<=3;i++)
	{
		if(d[i]=='+') ans+=gg[i+1];
		else if(d[i]=='-') ans-=gg[i+1];
	}
	for(int i=1;i<=4;i++) gg[i]=0;;
	ss.insert(ans);
}
void dfs2(int y)
{
	if(y==4)
	{
		judge();
		return;
	}
	for(int i=1;i<=3;i++)
	{
			d[y]=c[i];
			dfs2(y+1);
	}
}
void dfs1(int x)
{
	if(x==5)
	{
		dfs2(1);
		return;
	}
	for(int i=1;i<=4;i++)
	{
		if(vis[i]==0)
		{
			b[x]=a[i];
			vis[i]=1;
			dfs1(x+1);
			vis[i]=0;
		}
	}
}
void solve()
{
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	c[1]='+';
	c[2]='-';
	c[3]='*';
	dfs1(1);
	cout<<ss.size()<<'\n';
}

signed main()
{
	buff;
	int tt = 1;
	// cin >> tt;
	while (tt--)
	{
		solve();
	}
	return 0;
} 