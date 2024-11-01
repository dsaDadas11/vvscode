/*
 * @Author: dsaDadas11
 * @Date: 2024-02-18 20:48:18
 * @LastEditTime: 2024-02-18 20:48:25
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
	int n,r; cin>>n>>r;
	bool a[10007]={0};
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0,last=0;
	for(int i=1;i<=n;i++)
	{
		if(last>i) continue;
		bool flag=0;
		for(int j=i+r-1;j>=max(1LL,i-r+1);j--)
		{
			if(a[j]==1)
			{
				ans++;
				flag=1;
				last=j+r;
				break;
			}
		}
		if(!flag)
		{
			cout<<"-1"<<endl;
			return;
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