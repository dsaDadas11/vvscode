/*
 * @Author: dsaDadas11
 * @Date: 2024-03-11 12:24:51
 * @LastEditTime: 2024-03-11 12:24:56
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
	int a,b,c,d,e,f,g;
	cin>>a>>b>>c>>d>>e>>f>>g;
	if(a==0&&b==0&&c==0&&d==0&&e==0&&f==0)
	{
		cout<<g;
	}
	else
	{
		if(a!=0)
		{
			if(a==1) cout<<"m";
			else if(a==-1) cout<<"-m";
			else cout<<a<<"m";
		}
		if(b!=0)
		{
			if(b>0)
			{
				if(a!=0) cout<<"+";
			}
			if(b==1) cout<<"n";
			else if(b==-1) cout<<"-n";
			else cout<<b<<"n";
		}
		if(c!=0)
		{
			if(c>0)
			{
				if(a!=0||b!=0) cout<<"+";
			}
			if(c==1) cout<<"p";
			else if(c==-1) cout<<"-p";
			else cout<<c<<"p";
		}
		if(d!=0)
		{
			if(d>0)
			{
				if(a!=0||b!=0||c!=0) cout<<"+";
			}
			if(d==1) cout<<"i";
			else if(d==-1) cout<<"-i";
			else cout<<d<<"i";
		}
		if(e!=0)
		{
			if(e>0)
			{
				if(a!=0||b!=0||c!=0||d!=0) cout<<"+";
			}
			if(e==1) cout<<"j";
			else if(e==-1) cout<<"-j";
			else cout<<e<<"j";
		}
		if(f!=0)
		{
			if(f>0)
			{
				if(a!=0||b!=0||c!=0||d!=0||e!=0) cout<<"+";
			}
			if(f==1) cout<<"k";
			else if(f==-1) cout<<"-k";
			else cout<<f<<"k";
		}
		if(g!=0)
		{
			if(g>0)
			{
				if(a!=0||b!=0||c!=0||d!=0||e!=0||f!=0) cout<<"+";
			}
			cout<<g;
		}
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}