/*
 * @Author: dsaDadas11
 * @Date: 2024-11-09 13:12:42
 * @LastEditTime: 2024-11-09 13:13:52
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int n;
int a[N];
// 左边、右边比它大的最大个数
int dpl[N],dpr[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	// 先预处理左边
	dpl[1]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]>a[i])
			{
				dpl[i]=max(dpl[i],dpl[j]+1);
			}
		}
	}
	// 处理右边
	dpr[n]=0;
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>a[i])
			{
				dpr[i]=max(dpr[i],dpr[j]+1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dpl[i]+dpr[i]+1);
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