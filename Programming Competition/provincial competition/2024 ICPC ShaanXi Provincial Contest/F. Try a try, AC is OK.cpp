/*
 * @Author: dsaDadas11
 * @Date: 2024-09-02 18:50:14
 * @LastEditTime: 2024-09-02 18:51:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x;
void solve()
{
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		ans=max(x,ans);
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