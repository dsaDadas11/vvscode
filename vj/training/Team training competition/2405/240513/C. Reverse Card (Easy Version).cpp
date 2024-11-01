#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int n,m,ans=0;
	cin>>n>>m;
	// b
	for(int i=1;i<=m;i++)
	{
		// a
		ans+=(n+i)/(i*i);
	}
	ans--;
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}