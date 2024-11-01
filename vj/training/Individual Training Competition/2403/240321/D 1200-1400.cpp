/*
 * @Author: dsaDadas11
 * @Date: 2024-03-21 21:14:23
 * @LastEditTime: 2024-03-21 21:14:33
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e9;
int a[N];
/*
对于两个相邻的位置，如果ai <= ai+1, 我们要使得操作完后不影响这对大小关系，那么我们最大可以选择的数为x<=(a[i]+a[i+1])/2,
如果a[i]>a[i+1]则我们需要改变这对关系,最少选择x>=(a[i]+a[i+1]+1)/2
*/
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=0,r=2e9;
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			l=max(l,(a[i+1]+a[i]+1)/2);
		}
		if(a[i]<a[i+1])
		{
			r=min(r,(a[i+1]+a[i])/2);
		}
	}
	if(l>r) cout<<"-1"<<endl;
	else cout<<l<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}