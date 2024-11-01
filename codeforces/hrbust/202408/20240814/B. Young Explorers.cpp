/*
 * @Author: dsaDadas11
 * @Date: 2024-08-14 14:33:07
 * @LastEditTime: 2024-08-14 14:33:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int e[N]; // >=e
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>e[i];
	sort(e+1,e+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(e[i]==1)
		{
			ans++;
			continue;
		}
		int cnt=0;
		for(int j=i;j<=n;j++)
		{
			cnt++;
			if(e[j]<=cnt)
			{
				i=j;
				ans++;
				break;
			}
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