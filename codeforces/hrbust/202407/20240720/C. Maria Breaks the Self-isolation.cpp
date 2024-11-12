/*
 * @Author: dsaDadas11
 * @Date: 2024-07-20 14:52:44
 * @LastEditTime: 2024-07-20 14:52:50
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
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		if(a[i]>ans)
		{
			if(a[i]<=ans+1)
			{
				ans++;
				continue;
			}
			cnt++;
			for(int j=i+1;j<=n;j++)
			{
				cnt++;
				if(a[j]<=ans+cnt)
				{
					ans+=cnt;
					i+=cnt-1;
					break;
				}
				else
				{
					if(j==n)
					{
						cout<<ans+1<<endl;
						return;
					}
				}
			}
		}
		else ans++;
	}
	cout<<ans+1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}