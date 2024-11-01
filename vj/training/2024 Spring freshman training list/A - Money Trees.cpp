/*
 * @Author: dsaDadas11
 * @Date: 2024-04-16 13:32:29
 * @LastEditTime: 2024-04-16 13:33:49
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N],h[N];
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>h[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int pos=i;
		while(pos+1<=n&&h[pos]%h[pos+1]==0) ++pos;
		int l=i,r=i;
		int sum=a[l];
		while(l<=r+1&&r<=pos) //一定要写l<=r+1,不能写l<=r，也就是得遍历完[l,r]这个区间
		{
			if(sum>k)
			{
				sum-=a[l];
				++l;
			}
			else
			{
				ans=max(ans,r-l+1);
				++r;
				sum+=a[r];
			}
		}
		i=pos;
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

/*
另一AC代码：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N],h[N];
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>h[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,pos=i,sum=0;
		while(pos+1<=n&&h[pos]%h[pos+1]==0) ++pos;
		for(int i=l;i<=pos;i++)
		{
			sum+=a[i];
			while(sum>k&&l<=i) sum-=a[l++];
			if(sum<=k) ans=max(ans,i-l+1);
		}
		i=pos;
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
*/