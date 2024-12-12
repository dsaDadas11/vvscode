/*
 * @Author: dsaDadas11
 * @Date: 2024-12-02 19:58:29
 * @LastEditTime: 2024-12-02 19:58:34
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
int a[N];
int pre[N];
int cnt[N];
void solve()
{
	cin>>n;
	for(int i=0;i<=(n<<1);i++) cnt[i]=0;
	cnt[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]^a[i];
	}
	int ans=n*(n+1)/2;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j*j<(n<<1);j++)
		{
			int x=pre[i]^(j*j);
			if(x>(n<<1)) break;
			ans-=cnt[x];
		}	
		cnt[pre[i]]++;
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