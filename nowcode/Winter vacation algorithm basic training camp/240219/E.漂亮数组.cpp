/*
 * @Author: dsaDadas11
 * @Date: 2024-02-19 19:21:06
 * @LastEditTime: 2024-02-19 19:24:35
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int pre[N]; // 前缀和余数
void solve()
{
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		pre[i]=(pre[i-1]+x%k)%k;
	}
	set<int> se{0};
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(se.count(pre[i])) // 当前缀和余数pre[i]==pre[j]相等时，区间[j+1,i]的和就能被k整除
		{
			ans++;
			se.clear();
		}
		se.insert(pre[i]);
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