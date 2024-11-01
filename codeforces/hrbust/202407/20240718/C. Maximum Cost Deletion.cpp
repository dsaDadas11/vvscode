/*
 * @Author: dsaDadas11
 * @Date: 2024-07-18 14:39:20
 * @LastEditTime: 2024-07-18 14:39:25
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
	int n,a,b;
	string s;
	cin>>n>>a>>b>>s; // a*l+b
	int t1=a*n;
	int t2=0;
	if(b>=0) t2=b*n;
	else
	{
		map<char,int> mp;
		char c;
		for(int i=0;i<n;i++)
		{
			if(c!=s[i])
			{
				c=s[i];
				mp[c]++;
			}
		}
		t2=b*(min(mp['1'],mp['0'])+1);
	}
	cout<<t1+t2<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}