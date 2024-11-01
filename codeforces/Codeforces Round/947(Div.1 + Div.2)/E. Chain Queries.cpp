/*
 * @Author: dsaDadas11
 * @Date: 2024-09-29 17:31:22
 * @LastEditTime: 2024-09-29 17:43:29
 * @Description: go for it!
 */
/*
 解题思路：
 这道题挺复杂的，题目意思就是说要黑色的成一条链，
 每次查询会反转u的颜色，并让我们求黑色的是否为一条链
 看时间复杂度应该为q或者qlogn 因此我们必须得记录一下相关信息
 我们先想想怎么样才会构成一条链
 1.有且仅有一个节点的父节点为白色
   节点的子节点只有一个为黑色

 2.有且仅有一个节点的父节点为白色，且仅有该节点有两个子节点为黑色
  其余节点的子节点只有一个为黑色

 因此我们需要存的信息为
 1.该节点的父节点
 2.该节点为黑色且父节点为白色的数量
 3.节点的子节点的黑色数量
 4.节点的子节点的黑色数量为2的数量和大于2的数量
 5.节点的子节点的黑色数量为2的位置(用set存,只用于判断这个节点的父节点是否为白色)
 
 然后呢，我们需要考虑一下边界了，因为fa[1]=0，
 我们可以看作根节点的父节点是白色的，因此每当1变色的时候需要加减一下 f (该节点为黑色且父节点为白色的数量) 的数量
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,q;
int c[N];
vector<int> g[N];
int s[N]; // 该节点的子节点的黑色个数
int fa[N]; // 该节点的父节点
int c2,c3; // 节点的子节点有两个黑色的数量  >=3的数量
int f; // 父节点为白色且该节点为黑色的节点数量
set<int> se; // 存子节点黑色个数为2的节点
void init()
{
	for(int i=0;i<=n;i++)
	{
		g[i].clear();
		c2=c3=f=0;
		s[i]=fa[i]=0;
	}
	se.clear();
}
void dfs(int u,int fax)
{
	for(auto v:g[u])
	{
		if(v==fax) continue;
		fa[v]=u;
		s[u]+=c[v];
		dfs(v,u);
	}
}
void solve()
{
	cin>>n>>q;
	int u,v;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0); // 将1看作根节点
	for(int i=1;i<=n;i++)
	{
		if(s[i]==2) se.insert(i),c2++;
		else if(s[i]>2) c3++;
		if(c[i]==1&&c[fa[i]]==0) f++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>u;
		int fax=fa[u];
		// 如果一开始为黑色，要变成白色
		if(c[u]==1)
		{
			f+=s[u];
			if(u==1) f--;
			if(fax) // 只影响父节点
			{
				if(c[fax]==0) f--;
				if(s[fax]==2) c2--,se.erase(fax);
				else if(s[fax]>2) c3--;
				s[fax]--;
				if(s[fax]==2) c2++,se.insert(fax);
				else if(s[fax]>2) c3++;
			}
			c[u]=0;
		}
		else // 白变黑
		{
			f-=s[u];
			if(u==1) f++;
			if(fax)
			{
				if(c[fax]==0) f++;
				if(s[fax]==2) c2--,se.erase(fax);
				else if(s[fax]>2) c3--;
				s[fax]++;
				if(s[fax]==2) c2++,se.insert(fax);
				else if(s[fax]>2) c3++;
			}
			c[u]=1;
		}
		// 第一种情况
		if(f==1&&c2==0&&c3==0)
		{
			cout<<"YES"<<endl;
			continue;
		}
		// 第二种情况
		if(f==1&&c2==1&&c3==0&&c[fa[*se.begin()]]==0)
		{
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	init();
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}