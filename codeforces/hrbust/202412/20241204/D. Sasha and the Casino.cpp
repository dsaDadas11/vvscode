/*
 * @Author: dsaDadas11
 * @Date: 2024-12-04 18:48:09
 * @LastEditTime: 2024-12-04 18:48:17
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int k,x,a;
int tmp;
bool check(int mid)
{
	if((a-mid)+mid*k>tmp) return 0;
	return 1;
}
void solve()
{
	cin>>k>>x>>a;
	tmp=a;
	for(int i=1;i<=x;i++)
	{
		int l=1,r=a;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid)) l=mid+1;
			else r=mid;
		}
		a-=l;
		if(a<=0) return cout<<"NO"<<endl,void();
	}
	// i==x+1时必赢
	a*=k;
	if(a<=tmp) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}