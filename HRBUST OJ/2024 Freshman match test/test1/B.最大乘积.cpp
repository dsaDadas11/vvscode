/*
 * @Author: dsaDadas11
 * @Date: 2024-10-05 23:09:05
 * @LastEditTime: 2024-10-05 23:09:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int a[N];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	vector<int> ans;
	for(int i=0;i<=k;i++)
	{
		int t=1;
		for(int j=n-i+1;j<=n;j++)
		{
			t*=a[j];
		}
		for(int j=1;j<=k-i;j++)
		{
			t*=a[j];
		}
		ans.push_back(t);
	}
	sort(ans.begin(),ans.end());
	cout<<ans.back()<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}