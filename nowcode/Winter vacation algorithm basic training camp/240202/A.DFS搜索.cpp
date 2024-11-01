/*
 * @Author: dsaDadas11
 * @Date: 2024-02-02 18:55:24
 * @LastEditTime: 2024-02-02 18:56:17
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
	bool flag1=0,flag2=0,flag3=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='D'&&flag1==0) flag1=1;
		if(s[i]=='F'&&flag1==1) flag2=1;
		if(s[i]=='S'&&flag2==1) flag3=1;
	}
	if(flag3==1) cout<<1<<" ";
	else cout<<"0"<<" ";
	flag1=0,flag2=0,flag3=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='d'&&flag1==0) flag1=1;
		if(s[i]=='f'&&flag1==1) flag2=1;
		if(s[i]=='s'&&flag2==1) flag3=1;
	}
	if(flag3==1) cout<<1<<" ";
	else cout<<0<<" ";
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}