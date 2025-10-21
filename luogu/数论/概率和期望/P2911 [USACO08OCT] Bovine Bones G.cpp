/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-11-11 13:00:08
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y,z;
int cnt[107];
void solve()
{
	cin>>x>>y>>z;
	int ans=0;
	int maxn=0;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			for(int k=1;k<=z;k++)
			{
				cnt[i+j+k]++;
			}
		}
	}
	for(int i=1;i<=100;i++)
	{
		if(cnt[i]==0) continue;
		if(cnt[i]>maxn)
		{
			maxn=cnt[i];
			ans=i;
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