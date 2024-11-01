/*
 * @Author: dsaDadas11
 * @Date: 2024-07-24 14:51:24
 * @LastEditTime: 2024-07-24 14:51:35
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
int a[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	vector<int> ans;
	if(n%2==0)
	{
		int l=n/2,r=n/2;
		r++;
		while(r-l+1<=n)
		{
			ans.push_back(a[r]);
			ans.push_back(a[l]);
			l--,r++;
		}
	}
	else
	{
		ans.push_back(a[n/2+1]);
		for(int l=n/2,r=n/2+2;l>=1&&r<=n;l--,r++)
		{
			ans.push_back(a[r]);
			ans.push_back(a[l]);
		}
	}
	for(auto it:ans) cout<<it<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}