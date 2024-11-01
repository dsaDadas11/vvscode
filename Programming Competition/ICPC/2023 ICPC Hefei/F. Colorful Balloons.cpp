/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-10-24 10:44:50
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
string s;
void solve()
{
	cin>>n;
	map<string,int> mp;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mp[s]++;
	}
	bool flag=0;
	for(auto &[x,y]:mp)
	{
		if(1.0*y>0.5*n)
		{
			flag=1;
			cout<<x<<endl;
		}
	}
	if(!flag)
	{
		cout<<"uh-oh"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}