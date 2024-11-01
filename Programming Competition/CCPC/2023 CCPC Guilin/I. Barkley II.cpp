/*
 * @Author: dsaDadas11
 * @Date: 2024-10-15 19:47:42
 * @LastEditTime: 2024-10-15 22:05:44
 * @Description: go for it!
 */
/*
 解题思路：
 题目意思是：找一段区间，使其 不同元素种类-区间mex 最大
 因为最多只有n+1个数，所以可以枚举[1,n+1]中每个数不被包含的区间，
 然后就化为了找区间的不同元素种类，
 用树状数组+扫描线+离线查询(以r从小到大排序)，
 其实就是用树状数组进行差分，将前一个位置-1，这个位置+1，
 维持这个数在[1,r]的贡献一直为1
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int n,m;
int tr[N];
int lowbit(int x)
{
	return x&(-x);
}
void add(int p,int val)
{
	for(int i=p;i<N;i+=lowbit(i)) tr[i]+=val;
}
int ask(int p)
{
	int ans=0;
	for(int i=p;i;i-=lowbit(i)) ans+=tr[i];
	return ans;
}
struct op
{
	int x;
	int l,r;
	bool operator<(const op&rhs) const
	{
		return r<rhs.r;
	}
};
void solve()
{
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<=n+5;i++) tr[i]=0;
	vector<op> v;
	map<int,int> last,pre; // 记录a[i]的前一个位置
	for(int i=1;i<=n;i++)
	{
		last[i]=pre[a[i]];
		pre[a[i]]=i;
		if((i-1)-(last[i]+1)+1>0) v.push_back({a[i],last[i]+1,i-1});
	}
	// 特判 [i,n]
	for(int i=1;i<=n+1;i++)
	{
		if(pre[i]<n) v.push_back({i,pre[i]+1,n});
	}
	sort(v.begin(),v.end());
	int ans=-1;
	int i=0;
	for(auto [x,l,r]:v)
	{
		while(i<r)
		{
			i++;
			if(last[i]) add(last[i],-1);
			add(i,1);
		}
		int res=ask(r)-ask(l-1)-x;
		ans=max(res,ans);
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}