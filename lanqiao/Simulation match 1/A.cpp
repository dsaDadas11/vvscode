/*
 * @Author: dsaDadas11
 * @Date: 2024-11-09 12:17:01
 * @LastEditTime: 2024-11-09 13:15:13
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int p[N];
int a[N];
int cnt;
void init()
{
	a[1]=1;
	for(int i=2;i<N;i++)
	{
		if(!a[i]) p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<N;j++)
		{
			a[p[j]*i]=0;
			if(!i%p[j]) break;
		}
	}
}
void solve()
{
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(p[i]>2024) break;
		if(2024%p[i]==0) ans++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init();
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}