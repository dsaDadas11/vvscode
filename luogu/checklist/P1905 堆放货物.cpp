/*
 * @Author: dsaDadas11
 * @Date: 2024-09-18 22:22:26
 * @LastEditTime: 2024-09-18 22:24:55
 * @Description: go for it!
 */
/*
 解题思路：
 这道题我们需要把数组从大到小排序，然后根据值模拟地分配给1-p堆
 然后再反着给p-1堆
 从大到小的排原因是将3更平均的分配不至于任意两堆超过3
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n,p;
int a[M];
vector<int> ans[N];
void solve()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<int>()); // 从大到小排序
	int num=1;
	while(num<=n)
	{
		for(int i=1;i<=p&&num<=n;i++,num++)
		{
			ans[i].push_back(a[num]);
		}
		for(int i=p;i>=1&&num<=n;i--,num++)
		{
			ans[i].push_back(a[num]);
		}
	}
	for(int i=1;i<=p;i++)
	{
		for(auto j:ans[i])
		{
			cout<<j<<' ';
		}
		cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}