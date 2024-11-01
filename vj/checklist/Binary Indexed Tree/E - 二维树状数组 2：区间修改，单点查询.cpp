/*
 * @Author: dsaDadas11
 * @Date: 2024-03-09 15:36:56
 * @LastEditTime: 2024-03-09 15:37:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=5e3+7;
int n,m;
int tr[M][M];
int lowbit(int x){return x&(-x);}
void add(int x,int y,int val)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		for(int j=y;j<=m;j+=lowbit(j))
		{
			tr[i][j]+=val;
		}
	}
}
int sum(int x,int y)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
	{
		for(int j=y;j;j-=lowbit(j))
		{
			ans+=tr[i][j];
		}
	}
	return ans;
}
void solve()
{
	cin>>n>>m;
	int op;
	while(cin>>op)
	{
		if(op==1)
		{
			int x1,y1,x2,y2,k;
			cin>>x1>>y1>>x2>>y2>>k;
			add(x2+1,y2+1,k),add(x1,y1,k);
			add(x2+1,y1,-k),add(x1,y2+1,-k);
		}
		else
		{
			int x,y;
			cin>>x>>y;
			cout<<sum(x,y)<<endl;
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