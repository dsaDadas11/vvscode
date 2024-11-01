/*
 * @Author: dsaDadas11
 * @Date: 2024-07-22 21:53:31
 * @LastEditTime: 2024-07-22 21:53:36
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
	int n;
	cin>>n;
	int m=n/3;
	vector<int> a(m+1,3);
	if(n<=2)
	{
		m=1;
		a.resize(m+1);
	}
	a[1]+=n%3;
	set<pair<int,int> > s;
	for(int i=m;i>=1;i--)
	{
		for(int j=1;a[i]>0;j++)
		{
			if(i!=j&&!s.count(minmax(i,j)))
			{
				s.insert(minmax(i,j));
				a[i]--;
			}
		}
	}
	for(auto it:s)
	{
		cout<<it.first<<' '<<it.second<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}