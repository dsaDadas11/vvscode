/*
 * @Author: dsaDadas11
 * @Date: 2025-01-22 13:47:12
 * @LastEditTime: 2025-01-22 13:47:34
 * @Description: go for it!
 */
/*
 解题思路：
 双指针
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x,y;
int a[N];
void solve()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1;
	int ans=0,sum=0;
	for(int r=1;r<=n;r++)
	{
		sum+=a[r];
		while(l+1<=r&&sum>y)
		{
			sum-=a[l];
			l++;
		}
		if(sum>=x&&sum<=y)
		{
			ans++;
			sum=0;
			l=r+1;
		}
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