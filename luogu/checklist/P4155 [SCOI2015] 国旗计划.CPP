/*
 * @Author: dsaDadas11
 * @Date: 2024-08-26 22:53:10
 * @LastEditTime: 2024-08-26 22:53:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=4e5+7;
constexpr int M=2e3+7;
int n,m;
struct po
{
	int id,l,r;
	bool operator<(const po&a) const
	{
		return l<a.l;
	}
}a[N];
int ans[N];
int go[N][20];
void get_ans(int x)
{
	int len=a[x].l+m;
	int cur=x;
	int res=0;
	for(int i=19;i>=0;i--)
	{
		int pos=go[cur][i];
		if(pos&&a[pos].r<len)
		{
			res+=1<<i;
			cur=pos;
		}
	}
	ans[a[x].id]=res+2; // 此线段和最后一条线段
}
void multi()
{
	int p=1;
	int n2=n*2;
	// 初始化i的下一个位置
	for(int i=1;i<=n2;i++)
	{
		while(p<=n2&&a[p].l<=a[i].r) p++;
		go[i][0]=p-1;
	}
	for(int j=1;j<20;j++)
	{
		for(int i=1;i<=n2;i++)
		{
			go[i][j]=go[go[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=n;i++) get_ans(i);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i].id=i;
		cin>>a[i].l>>a[i].r;
		if(a[i].l>a[i].r) a[i].r+=m;
	}
	sort(a+1,a+1+n);
	// 加倍成链
	for(int i=1;i<=n;i++)
	{
		a[i+n].id=a[i].id;
		a[i+n].l=a[i].l+m;
		a[i+n].r=a[i].r+m;
	}
	multi();
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}