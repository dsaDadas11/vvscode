/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-08-14 14:11:07
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,k;
void solve()
{
	cin>>a>>k;
	int t=0;
	int maxn,minn;
	for(int i=2;i<=k;i++)
	{
		t=a;
		maxn=-1e18,minn=1e18;
		while(t>0)
		{
			int yu=t%10;
			maxn=max(maxn,yu);
			minn=min(minn,yu);
			t/=10;
		}
		if(minn==0) break;
		a+=maxn*minn;
	}
	cout<<a<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}