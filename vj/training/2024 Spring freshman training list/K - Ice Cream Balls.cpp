/*
 * @Author: dsaDadas11
 * @Date: 2024-04-18 18:50:19
 * @LastEditTime: 2024-04-18 18:50:32
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
bool check(int mid)
{
	if(mid*(mid-1)/2<=n) return 1;
	return 0;
}
void solve()
{
	cin>>n;
	int l=1,r=2e9;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l+(n-l*(l-1)/2)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}