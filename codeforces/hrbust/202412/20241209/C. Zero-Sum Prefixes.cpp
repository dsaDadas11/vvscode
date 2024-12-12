/*
 * @Author: dsaDadas11
 * @Date: 2024-12-09 20:29:47
 * @LastEditTime: 2024-12-09 20:30:00
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
int sum[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	vector<int> z0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) z0.push_back(i);
	}
	z0.push_back(n+1);
	int ans=0;
	for(int i=0;i<z0.size()-1;i++)
	{
		map<int,int> mp;
		for(int j=z0[i];j<=z0[i+1]-1;j++)
		{
			mp[sum[j]]++;
		}
		int maxn=0,cnt=0;
		for(auto [x,y]:mp)
		{
			if(cnt<y)
			{
				cnt=y;
				maxn=x;
			}
		}
		ans+=cnt;
	}

	for(int i=1;i<z0[0];i++)
	{
		if(sum[i]==0) ans++;
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