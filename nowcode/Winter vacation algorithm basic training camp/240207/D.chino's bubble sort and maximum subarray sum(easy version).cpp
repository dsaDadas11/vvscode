/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-02-17 18:46:16
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
	int n,k; cin>>n>>k;
	int a[10007]={0},pre[1007]={0};
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=INT_MIN;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(pre[i-1]>0) pre[i]=pre[i-1]+a[i];
			else pre[i]=a[i];
		}
		for(int i=1;i<=n;i++) ans=max(ans,pre[i]);
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			swap(a[i-1],a[i]);
			for(int i=1;i<=n;i++)
			{
				if(pre[i-1]>0) pre[i]=pre[i-1]+a[i];
				else pre[i]=a[i];
			}
			for(int i=1;i<=n;i++) ans=max(ans,pre[i]);
			swap(a[i-1],a[i]);
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