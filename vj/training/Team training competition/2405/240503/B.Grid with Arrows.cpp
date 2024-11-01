/*
 * @Author: dsaDadas11
 * @Date: 2024-05-08 19:09:09
 * @LastEditTime: 2024-05-08 19:14:39
 * @Description: go for it!
 */
/*
本题思路：
1.建图，把各个点转化成一条条边连起来，并计算入度和出度
2.并查集，用来查看图之间是否连通(是否存在多个图)
3.如果要一遍跑完整个图，必须是一条直链或者环状或者一段直链加一段环
  这个时候用入度和出度就行了(如果用dfs跑图感觉挺麻烦要跑两个端 os:肯定不是我不会)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s[N];
int a[N];
int n,m;
int ind[N],outd[N];
int fa[N];
int find1(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find1(fa[x]);
}
void add1(int x,int y)
{
	fa[find1(x)]=find1(y);
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<=n*m;i++)
	{
		fa[i]=i;
		ind[i]=0;
		outd[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]=' '+s[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[(i-1)*m+j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int pos=(i-1)*m+j;
			if(s[i][j]=='u'&&i-a[pos]>=1)
			{
				outd[pos]++;
				ind[(i-a[pos]-1)*m+j]++;
				add1(pos,(i-a[pos]-1)*m+j);
			}
			else if(s[i][j]=='d'&&i+a[pos]<=n)
			{
				outd[pos]++;
				ind[(i+a[pos]-1)*m+j]++;
				add1(pos,(i+a[pos]-1)*m+j);
			}
			else if(s[i][j]=='l'&&j-a[pos]>=1)
			{
				outd[pos]++;
				ind[(i-1)*m+j-a[pos]]++;
				add1(pos,(i-1)*m+j-a[pos]);
			}
			else if(s[i][j]=='r'&&j+a[pos]<=m)
			{
				outd[pos]++;
				ind[(i-1)*m+j+a[pos]]++;
				add1(pos,(i-1)*m+j+a[pos]);
			}
		}
	}
	int in=0,out=0,pd=0;
	for(int i=1;i<=n*m;i++)
	{
		if(fa[i]==i) pd++;
		if(pd>1)
		{
			cout<<"No"<<endl;
			return;
		}
		if(ind[i]==0) in++;
		if(outd[i]==0) out++;
	}
	if((in==0&&out==0)||(in==1&&out==1)) cout<<"Yes"<<endl;
	else if((in==0&&out==1)||(in==1&&out==0)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}