/*
 * @Author: dsaDadas11
 * @Date: 2024-11-09 12:59:59
 * @LastEditTime: 2024-11-09 13:14:04
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,x,k;
int od[N],en[N];
int sum1[N],sum2[N];
void solve()
{
	cin>>n>>k;
	int len1=0,len2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(i&1) od[++len1]=x;
		else en[++len2]=x;
	}
	for(int i=1;i<=len1;i++)
	{
		sum1[i]=sum1[i-1]+od[i];
	}
	for(int i=1;i<=len2;i++)
	{
		sum2[i]=sum2[i-1]+en[i];
	}
	int ans=0;
	for(int i=1;i+k-1<=len1;i++)
	{
		ans=max(ans,sum1[i+k-1]-sum1[i-1]);
	}
	for(int i=1;i+k-1<=len2;i++)
	{
		ans=max(ans,sum2[i+k-1]-sum2[i-1]);
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