/*
 * @Author: dsaDadas11
 * @Date: 2024-12-07 11:38:30
 * @LastEditTime: 2024-12-07 11:50:41
 * @Description: go for it!
 */
/*
 解题思路：
 要求区间 [l,r] al...ar  均等于模 m 的最大 m
 例如：14，2，6 最多能模 4
 那么有式子 a[i]%m=a[i+1]%m, 移项得 (a[i+1]-a[i])%m=0
 因此我们可以求一个差分数组，但是因为d[l]为a[l]-a[l-1]的值，a[l-1]不在区间[l,r]内
 因此我们只需要求 [l+1,r] 的 gcd 即可，然后再 gcd(gcd[l+1,r],a[l+1]-a[l])
 因此可以看出只需要求 gcd(l+1,r) 即可
 可用 st表或者线段树维护区间 gcd
 但是需要特判l=r时 模只能为0
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,q;
int a[N];
int d[N];
int f[N][20];
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	for(int j=0;j<20;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			if(j==0) f[i][j]=d[i];
			else f[i][j]=__gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	while(q--)
	{
		int l,r; cin>>l>>r;
		if(l==r)
		{
			cout<<0<<' ';
			continue;
		}
		l++;
		int len=r-l+1;
		int k=log(len)/log(2);
		int ans=abs(__gcd(f[l][k],f[r-(1<<k)+1][k]));
		cout<<ans<<' ';
	}
	cout<<endl;

}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}