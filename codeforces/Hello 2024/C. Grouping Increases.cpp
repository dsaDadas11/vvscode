/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 15:02:20
 * @LastEditTime: 2024-01-17 15:02:26
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int a[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	int x=-1,y=-1;
	for(int i=1;i<=n;i++)
	{
		if(x==-1)
		{
			x=a[i];
			continue;
		}
		if(x>=a[i])
		{
			if(y>=a[i])
			{
				if(x<y) x=a[i];
				else y=a[i];
				continue;
			}
			else
			{
				x=a[i];
				continue;
			}
		}
		else
		{
			if(y==-1)
			{
				y=a[i];
				continue;
			}
			if(y>=a[i])
			{
				y=a[i];
				continue;
			}
			if(x<y) x=a[i];
			else y=a[i];
			ans++;
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