/*
 * @Author: dsaDadas11
 * @Date: 2024-12-11 18:34:36
 * @LastEditTime: 2024-12-11 18:37:16
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
int x,y;
void solve()
{
	cin>>n;
	vector<int> v1,v2;
	
	for(int i=1;i<=2*n;i++)
	{
		cin>>x>>y;
		if(x==0) v1.push_back(abs(y));
		else v2.push_back(abs(x));
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	long double ans=0.0;
	for(int i=0;i<v1.size();i++)
	{
		ans+=sqrt(v1[i]*v1[i]+v2[i]*v2[i]);
	}
	cout<<fixed<<setprecision(18)<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}