/*
 * @Author: dsaDadas11
 * @Date: 2024-08-27 21:33:01
 * @LastEditTime: 2024-08-27 21:35:36
 * @Description: go for it!
 */
/*
解题思路：
首先要注意的点是当前的话表示X吃X，就是假话。这需要op==2才成立
其次如何构建权值并查集呢？
我们可以将权值设为 0为同类 1为A吃B 2为A被B吃 并模3
这样可以保证A->B  B->C 则 A->C
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e4+7;
constexpr int M=2e3+7;
int n,k;
int ans;
int fa[N];
int d[N]; // 0为同类 1为A吃B 2为A被B吃
int findfa(int x)
{
	if(fa[x]!=x)
	{
		int t=fa[x];
		fa[x]=findfa(fa[x]);
		d[x]=(d[x]+d[t])%3;
	}
	return fa[x];
}
void merge(int x,int y,int val)
{
	int rootx=findfa(x);
	int rooty=findfa(y);
	if(rootx==rooty)
	{
		if(((d[x]-d[y])%3+3)%3!=val) ans++;
	}
	else
	{
		fa[rootx]=rooty;
		d[rootx]=(d[y]-d[x]+val)%3;
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=0;i<N;i++)
	{
		fa[i]=i;
		d[i]=0;
	}
	int op,x,y;
	for(int i=1;i<=k;i++)
	{
		cin>>op>>x>>y;
		if(x>n||y>n)
		{
			ans++;
			continue;
		}
		if(x==y&&op==2)
		{
			ans++;
			continue;
		}
		if(op==1)
		{
			merge(x,y,0);
		}
		else
		{
			merge(x,y,1);
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