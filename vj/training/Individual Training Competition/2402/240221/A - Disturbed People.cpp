/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-02-21 20:39:01
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
	bool a[107]={0};
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=2;i<n;i++)
	{
		if(a[i-1]==1&&a[i]==0&&a[i+1]==1)
		{
			ans++;
			a[i+1]=0;
		}
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