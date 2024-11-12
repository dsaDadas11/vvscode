/*
 * @Author: dsaDadas11
 * @Date: 2024-02-17 18:55:35
 * @LastEditTime: 2024-02-17 18:55:48
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
	int n; cin>>n;
	string s; cin>>s;
	map<int,bool> p;
	int temp=n;
	for(int i=1;i<=n;i++)
	{
		if(temp%i==0)
		{
			p[i]=1;
		}
	}
	for(auto it=p.begin();it!=p.end();it++)
	{
		reverse(s.begin(),s.begin()+it->first);
	}
	cout<<s<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}