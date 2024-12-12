/*
 * @Author: dsaDadas11
 * @Date: 2024-12-11 20:31:42
 * @LastEditTime: 2024-12-11 22:04:22
 * @Description: go for it!
 */
/*
 裴蜀定理
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int a[N];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			cout<<"YES"<<endl;
			return;
		}
	}
	int gg=0;
	for(int i=2;i<=n;i++)
	{
		gg=__gcd(gg,a[i]-a[i-1]);
	}
	if((k-a[1])%gg==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}