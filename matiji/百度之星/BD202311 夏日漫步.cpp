/*
 * @Author: dsaDadas11
 * @Date: 2024-05-28 19:52:21
 * @LastEditTime: 2024-05-28 19:59:53
 * @Description: go for it!
 */
/*
解题思路：
1.注意如何瞬移(用的map+set维护，也可以多开一个next数组维护)，并且瞬移后往回走可能消耗体力值更小
2.注意边界及体力的转移条件
3.if(tt==n)时不要用return,会爆内存
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N],d[N];
queue<int> q;
map<int,set<int> > mp;
void bfs()
{
	for(int i=1;i<=n;i++) d[i]=1e18;
	d[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int tt=q.front();
		q.pop();
		if(tt==n)
		{
			cout<<d[n]<<endl;
			break;
		}
		// 往前走
		if(tt-1>=1&&d[tt]+1<d[tt-1])
		{
			q.push(tt-1);
			d[tt-1]=d[tt]+1;
		}
		// 往后走
		if(tt+1<=n&&d[tt]+1<d[tt+1])
		{
			q.push(tt+1);
			d[tt+1]=d[tt]+1;
		}
		// 瞬移
		auto it=mp[a[tt]].find(tt);
		it=next(it);
		if(it!=mp[a[tt]].end()&&d[tt]+1<d[*it])
		{
			q.push(*it);
			d[*it]=d[tt]+1;
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]].insert(i);
	}
	bfs();
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
next数组用法：

int ne[N],idx[N];
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	idx[i]=i;
}
sort(idx+1,idx+1+n,[](int x,int y){return a[x]<a[y];});
for(int i=1;i<=n;i++)
{
	if(a[idx[i]]==a[idx[i+1]])
	{
		ne[idx[i]]=idx[i+1];
	}
}

*/