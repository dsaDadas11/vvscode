/*
 * @Author: dsaDadas11
 * @Date: 2024-11-16 12:10:53
 * @LastEditTime: 2024-11-19 13:26:46
 * @Description: go for it!
 */
/*
 解题思路：
 因为我们可以跳到后面更矮的树，再从更矮的树跳到前面大的树，
 因此我们可以通过后面的答案更新前面的答案
 假设[i+1,n]的ans已经确定，
 如果max[1,i]<=min[i+1,n] 那么不能跳，答案即为ans[i]=max[1,i]
 如果max[1,i]>min[i+1,n] 说明可以跳到后面的位置，我们只需要二分找到这个值最大即可(在最右边)
 其实可以不用二分，因为如果可以跳的话，我们总能从i位置跳到i+1的位置，那么ans[i]即为ans[i+1]

 因为区间最值一直为[1,x]或者[x,n]，因此我们可以处理前后缀而不用st表
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int n;
int a[N],ans[N];
int f1[N][20],f2[N][20];
int len,k,res,resm,res1;
int l,r,mid;
int find_max(int l,int r)
{
	len=r-l+1;
	k=log(len)/log(2);
	res1=max(f1[l][k],f1[r-(1<<k)+1][k]);
	return res1;
}
int find_min(int l,int r)
{
	len=r-l+1;
	k=log(len)/log(2);
	res1=min(f2[l][k],f2[r-(1<<k)+1][k]);
	return res1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1) return cout<<a[1]<<endl,void();
	for(int j=0;j<20;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			if(j==0) f1[i][j]=a[i];
			else f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
		}
	}
	for(int j=0;j<20;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			if(j==0) f2[i][j]=a[i];
			else f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
		}
	}
	ans[n]=find_max(1,n);
	for(int i=n-1;i>=1;i--)
	{
		res=find_min(i+1,n);
		resm=find_max(1,i);
		if(resm<=res)
		{
			ans[i]=resm;
			continue;
		}
		l=i+1,r=n;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(find_min(mid,n)<resm) l=mid;
			else r=mid-1;
		}
		ans[i]=ans[l];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
 并查集写法：
 一个点可以往左跳和往右跳的点可以放在一个连通块内，然后父节点设为连通块的最大值即可，
 优化：
 假设[1,i-1]都已经处理完成，被push入pq中了，
 当a[i]>前面连通块的最大值的时候，就说明这个点可以跳到连通块中，因此加入连通块，
 此时需要合并，将连通块的最大值和当前的索引i push入队列即可

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int fa[N];
int a[N];
int find_fa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find_fa(fa[x]);
}
void merge(int x,int y)
{
	int fax=find_fa(x);
	int fay=find_fa(y);
	if(a[fax]>a[fay]) swap(fax,fay);
	fa[fax]=fay;
}
priority_queue<pair<int,int> > pq;
void solve()
{
	cin>>n;
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=0;
		while(!pq.empty())
		{
			auto [val,x]=pq.top();
			if(val<=a[i]) break;
			pq.pop();
			flag=1;
			merge(x,i);
		}
		if(flag) pq.push({a[find_fa(i)],i});
		else pq.push({a[i],i});
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[find_fa(i)]<<' ';
	}
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