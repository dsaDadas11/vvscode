/*
 * @Author: dsaDadas11
 * @Date: 2024-12-03 13:10:40
 * @LastEditTime: 2024-12-03 13:32:41
 * @Description: go for it!
 */
/*
 解题思路：
 区间分组求最大值典型题的稍微小变形
 典型题：https://codeforces.com/contest/1903/problem/C

 我们贪心的找后缀最大的值就行
 hack: 要注意第一个元素一定要先分组
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
int suf[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	suf[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+a[i];
	}
	vector<pair<int,int> > v;
	for(int i=2;i<=n;i++) // 第一个元素单独处理
	{
		v.push_back({suf[i],i});
	}
	sort(v.begin(),v.end());
	int ans=0;
	ans+=suf[1];
	cout<<ans<<' ';
	for(int i=n-2;i>=0;i--)
	{
		ans+=suf[v[i].second];
		cout<<ans<<' ';
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