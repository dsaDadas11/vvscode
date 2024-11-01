/*
 * @Author: dsaDadas11
 * @Date: 2024-04-27 22:52:41
 * @LastEditTime: 2024-04-28 16:55:38
 * @Description: go for it!
 */
/*
这道题关键思路在于
1.找到每个数的左右边界范围并排序
2.找右边界+1的值的位置的前一位，用vector维护值种类
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int val,pos,res[N];
struct op
{
	int id;
	int l1,r1;
	int d;
	bool operator<(const op& that) const
	{
		if(d!=that.d) return d<that.d;
		return l1>that.l1;
	}
}a[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i].id=i,a[i].l1=1,a[i].r1=n;
		a[i].d=a[i].r1-a[i].l1+1;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>val>>pos;
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(pos<=mid)
			{
				a[mid].l1=max(a[mid].l1,val);
				r=mid;
			}
			else
			{
				a[mid].r1=min(a[mid].r1,val-1);
				l=mid+1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[i].d=a[i].r1-a[i].l1+1;
		if(a[i].d<=0)
		{
			cout<<"-1"<<endl;
			return;
		}
	}
	sort(a+1,a+1+n);
	vector<int> v(n+1);
	for(int i=0;i<=n;i++) v[i]=i;
	for(int i=1;i<=n;i++)
	{
		int p=a[i].id;
		int p1=lower_bound(v.begin()+1,v.end(),a[i].r1+1)-v.begin();
		if(p1==1)
		{
			cout<<"-1"<<endl;
			return;
		}
		p1--;
		if(v[p1]>=a[i].l1)
		{
			res[p]=v[p1];
			v.erase(v.begin()+p1);
		}
		else
		{
			cout<<"-1"<<endl;
			return;
		}
	}
	for(int i=1;i<=n;i++) cout<<res[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

// dfs表示二分写法
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int val,pos,res[N];
struct op
{
	int id;
	int l1,r1;
	int d;
	bool operator<(const op& that) const
	{
		return d<that.d;
	}
}a[N];
void dfs(int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)>>1;
	if(pos<=mid)
	{
		a[mid].l1=max(a[mid].l1,val);
		dfs(l,mid);
	}
	else
	{
		a[mid].r1=min(a[mid].r1,val-1);
		dfs(mid+1,r);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i].id=i,a[i].l1=1,a[i].r1=n;
		a[i].d=a[i].r1-a[i].l1+1;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>val>>pos;
		dfs(1,n);
	}
	for(int i=1;i<=n;i++)
	{
		a[i].d=a[i].r1-a[i].l1+1;
		if(a[i].d<=0)
		{
			cout<<"-1"<<endl;
			return;
		}
	}
	sort(a+1,a+1+n);
	vector<int> v(n+1);
	for(int i=0;i<=n;i++) v[i]=i;
	for(int i=1;i<=n;i++)
	{
		int p=a[i].id;
		int p1=lower_bound(v.begin()+1,v.end(),a[i].r1+1)-v.begin();
		if(p1==1)
		{
			cout<<"-1"<<endl;
			return;
		}
		p1--;
		if(v[p1]>=a[i].l1)
		{
			res[p]=v[p1];
			v.erase(v.begin()+p1);
		}
		else
		{
			cout<<"-1"<<endl;
			return;
		}
	}
	for(int i=1;i<=n;i++) cout<<res[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/