/*
 * @Author: dsaDadas11
 * @Date: 2024-11-10 12:44:33
 * @LastEditTime: 2024-11-10 12:44:43
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
void solve()
{
	cin>>n;
	int sum=0;
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<=n&&j*i<=n;j++)
		{
			tmp+=j*i;
		}
		if(tmp>sum)
		{
			sum=tmp;
			ans=i;
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