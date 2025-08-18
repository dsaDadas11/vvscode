/*
 * @Author: dsaDadas11
 * @Date: 2024-09-17 21:31:23
 * @LastEditTime: 2024-09-17 21:46:02
 * @Description: go for it!
 */
/*
 很奇怪的一道题
 虽然说和 P1020 导弹拦截 这道题类似，求最长上升子序列
 但是不能枚举每个区间[1,i] 和 [i,n] 的最长上升子序列和最长下降子序列
 只用一个for循环就能求出区间的最大pre和suf

 后来发现可以这样做.....
 原来是我把mid写成cnt了我焯.....
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int h[107];
int pre[107],suf[107];
int g[107];
//[1,i]最长上升子序列  [i,n]最长下降子序列
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	int cnt=0;
	g[0]=-2e9;
	for(int i=1;i<=n;i++)
	{
		if(h[i]>g[cnt]) g[++cnt]=h[i];
		else
		{
			int l=1,r=cnt;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(h[i]>g[mid]) l=mid+1;
				else r=mid;
			}
			g[l]=h[i];
		}
		pre[i]=cnt;
	}
	cnt=0;
	for(int i=n;i>=1;i--)
	{
		if(h[i]>g[cnt]) g[++cnt]=h[i];
		else
		{
			int l=1,r=cnt;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(h[i]>g[mid]) l=mid+1;
				else r=mid;
			}
			g[l]=h[i];
		}
		suf[i]=cnt;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,(pre[i]+suf[i]-1));
	}
	cout<<n-ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
 遍历区间做法：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int h[107];
int pre[107],suf[107];
int g[107];
//[1,j]最长上升子序列  [j,n]最长下降子序列
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int j=1;j<=n;j++)
	{
		int cnt=0;
		memset(g,0,sizeof g);
		g[0]=-2e9;
		for(int i=1;i<=j;i++)
		{
			if(h[i]>g[cnt]) g[++cnt]=h[i];
			else
			{
				int l=1,r=cnt;
				while(l<r)
				{
					int mid=(l+r)>>1;
					if(h[i]>g[mid]) l=mid+1;
					else r=mid;
				}
				g[l]=h[i];
			}
		}
		pre[j]=cnt;
	}
	for(int j=1;j<=n;j++)
	{
		int cnt=0;
		memset(g,0,sizeof g);
		g[0]=2e9;
		for(int i=j;i<=n;i++)
		{
			if(h[i]<g[cnt]) g[++cnt]=h[i];
			else
			{
				int l=1,r=cnt;
				while(l<r)
				{
					int mid=(l+r)>>1;
					if(h[i]<g[mid]) l=mid+1;
					else r=mid;
				}
				g[l]=h[i];
			}
		}
		suf[j]=cnt;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,(pre[i]+suf[i]-1));
	}
	cout<<n-ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/