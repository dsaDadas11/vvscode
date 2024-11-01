/*
 * @Author: dsaDadas11
 * @Date: 2024-03-19 22:47:32
 * @LastEditTime: 2024-03-19 22:48:08
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int n; cin>>n;
	int a[107]={0};
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int sum=1;
		for(int j=1;j<=n;j++)
		{
			if(j==i) sum*=(a[j]+1);
			else sum*=a[j];
		}
		ans=max(ans,sum);
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