/*
 * @Author: dsaDadas11
 * @Date: 2024-10-13 17:00:17
 * @LastEditTime: 2024-10-13 17:01:40
 * @Description: go for it!
 */
/*
 解题思路：
 一开始想的是 怎么让 xi*ki 基本一致呢？
 可以求其lcm让xi*ki相等，然后判断一下就行
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int k[57];
void solve()
{
	cin>>n;
	int lc=1;
	for(int i=1;i<=n;i++) cin>>k[i],lc=lc*k[i]/__gcd(lc,k[i]);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=lc/k[i];
	}
	if(sum>=lc) return cout<<"-1"<<endl,void();
	for(int i=1;i<=n;i++)
	{
		cout<<lc/k[i]<<' ';
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