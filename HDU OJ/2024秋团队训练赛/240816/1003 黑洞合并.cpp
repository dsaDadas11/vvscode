/*
 * @Author: dsaDadas11
 * @Date: 2024-08-17 15:46:12
 * @LastEditTime: 2024-08-17 15:46:31
 * @Description: go for it!
 */
/*
 不懂，与次序无关
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n;
int w[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	int ans=0;
	for(int i=1;i<=n-1;i++)
	{
		int x=1,y=n-i+1;
		ans=(ans+((((w[x]*w[y])%mod)*w[x])%mod+(((w[x]*w[y])%mod)*w[y]))%mod)%mod;
		ans=(ans+mod)%mod;
		w[x]=w[x]+w[y];
		w[x]%=mod;
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