/*
 * @Author: dsaDadas11
 * @Date: 2024-11-09 12:36:38
 * @LastEditTime: 2024-11-09 13:14:24
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[37]={0,9226, 4690, 4873, 1285, 4624, 1596, 6982, 590, 8806, 121, 8399, 8526, 5426, 64, 9655, 7705, 3929, 3588, 7397, 8020, 1311, 5676, 3469, 2325, 1226, 8203, 9524, 3648, 5278, 8647};
int cnt[107];
void solve()
{
	// 统计1的个数
	int len=0;
	for(int i=1;i<=30;i++)
	{
		vector<int> v;
		int t=a[i];
		while(t)
		{
			v.push_back(t&1);
			t>>=1;
		}
		reverse(v.begin(),v.end());
		for(int i=0;i<(int)v.size();i++)
		{
			if(v[i]==1) cnt[i]++;
		}
		len=max(len,(int)v.size());
	}
	int p=1;
	int ans=0;
	for(int i=0;i<len;i++)
	{
		// 0 > 1
		if(cnt[i]<15)
		{
			ans+=p;
		}
		p*=2;
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