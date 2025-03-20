/*
 * @Author: dsaDadas11
 * @Date: 2025-03-16 21:10:29
 * @LastEditTime: 2025-03-16 21:10:39
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
struct op
{
	int val,len;
};
int n,m;
int a[M][M];
op stk[M];
int p;
char ch;
int calc(int x)
{
	int res=0;
	p=0;
	for(int i=1;i<=m;i++)
	{
		int w=0;
		while(p&&a[x][i]<=stk[p].val)
		{
			w+=stk[p].len;
			res=max(res,w*stk[p].val);
			p--;
		}
		stk[++p]={a[x][i],w+1};
	}
	int w=0;
	while(p)
	{
		w+=stk[p].len;
		res=max(res,stk[p].val*w);
		p--;
	}
	return res;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='F') a[i][j]=a[i-1][j]+1;
			else a[i][j]=0;
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,calc(i));
	cout<<3*ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}