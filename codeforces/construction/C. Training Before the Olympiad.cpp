/*
 * @Author: dsaDadas11
 * @Date: 2024-08-28 21:39:44
 * @LastEditTime: 2024-08-28 21:40:00
 * @Description: go for it!
 */
// URL:https://codeforces.com/problemset/problem/1916/C
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int odd=0;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(a[i]%2) odd++;
		if(i==1)
		{
			cout<<a[i]<<' ';
			continue;
		}
		else if(i==2)
		{
			cout<<(sum/2)*2<<' ';
			continue;
		}
		/*
		先手消耗 2 个奇数 后手消耗 1 个奇数 1 个偶数
		奇数被先消耗完
		*/
		int yu=odd%3;
		int chu=odd/3;
		if(yu==1) chu++;
		cout<<sum-chu<<' ';
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