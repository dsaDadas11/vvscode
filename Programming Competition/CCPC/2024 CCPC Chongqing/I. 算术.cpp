/*
 * @Author: dsaDadas11
 * @Date: 2025-01-12 17:30:12
 * @LastEditTime: 2025-01-16 11:56:47
 * @Description: go for it!
 */
/*
 解题思路：
 这道题一开始看着很懵，不知道怎么加怎么乘
 首先，当 x,y > 1时，x*y >= x+y (x=y=2时等号成立)
 因此在 2以上我们只需要考虑乘法，而 1只需要考虑加法
 又有一个新问题了，1的时候应该怎么加？
 那么我们可以将 1分成两组
 第一组：i 用来被第二组的 1进行加操作，进而和 2以上的数进行乘
 第二组：yu-i 用来加第一组和 2以上的数，缩小他们之间的差距，使乘积更大
 用优先队列维护即可 

 要注意的是会爆long long，要用log找最大值  (log10 比 log 慢)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int a[17];
void solve()
{
	for(int i=1;i<=9;i++) cin>>a[i];
	long double ans=0;
	vector<int> res;
	// 将a[1]分组
	for(int i=0;i<=a[1];i++)
	{
		priority_queue<int,vector<int>,greater<> > pq;
		for(int j=1;j<=i;j++)
		{
			pq.push(1);
		}
		for(int j=2;j<=9;j++)
		{
			for(int k=1;k<=a[j];k++)
			{
				pq.push(j);
			}
		}
		if(pq.empty()) continue;
		int yu=a[1]-i;
		int tmp;
		for(int j=1;j<=yu;j++)
		{
			tmp=pq.top();
			pq.pop();
			pq.push(tmp+1);
		}
		long double anst=0;
		vector<int> rest;
		while(!pq.empty())
		{
			anst+=log(pq.top());
			rest.push_back(pq.top());
			pq.pop();
		}
		if(anst>ans)
		{
			ans=anst;
			res=rest;
		}
	}
	int sum=1;
	for(auto x:res)
	{
		sum*=x;
		sum%=mod;
	}
	cout<<sum<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}