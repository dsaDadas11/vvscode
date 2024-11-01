/*
 * @Author: dsaDadas11
 * @Date: 2024-01-29 13:04:21
 * @LastEditTime: 2024-01-29 13:04:26
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n,h; cin>>n>>h;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int k=1;k<=3;k++)
	{
		int kind=1;
		int i=0;
		int t=h;
		while(i<n)
		{
			if(t>a[i+1]) t+=a[i+1]/2,i++;
			else if(kind==4) break;
			else
			{
				if(kind==k) t*=3;
				else t*=2;
				kind++;
			}
		}
		ans=max(ans,i);
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