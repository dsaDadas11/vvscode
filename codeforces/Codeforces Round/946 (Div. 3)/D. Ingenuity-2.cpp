/*
 * @Author: dsaDadas11
 * @Date: 2024-09-25 21:20:15
 * @LastEditTime: 2024-09-25 21:21:48
 * @Description: go for it!
 */
/*
 很奇葩的模拟
 特判条件看代码就好
 注意N-S=0和E-W=0时不能同时使用R或H
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
	cin>>n>>s;
	int N=0,S=0,W=0,E=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='N') N++;
		else if(s[i]=='S') S++;
		else if(s[i]=='W') W++;
		else E++;
	}
	if((N-S)%2||(E-W)%2)
	{
		cout<<"NO"<<endl;
		return;
	}
	if(n==2&&((N==1&&S==1)||(E==1&&W==1)))
	{
		cout<<"NO"<<endl;
		return;
	}
	if(N-S==0)
	{
		int cntn=0,cnts=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='N'&&cntn==0) s[i]='R',cntn++;
			if(s[i]=='S'&&cnts==0) s[i]='R',cnts++;
		}
	}
	if(E-W==0)
	{
		int cntw=0,cnte=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='W'&&cntw==0) s[i]='H',cntw++;
			if(s[i]=='E'&&cnte==0) s[i]='H',cnte++;
		}
	}
	// 处理N,S
	int ave=abs(N-S)/2;
	if(N>S)
	{
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='N'&&cnt<ave)
			{
				cnt++;
				s[i]='R';
			}
		}
	}
	else if(N<S)
	{
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='S'&&cnt<ave)
			{
				cnt++;
				s[i]='R';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='N'||s[i]=='S')
		{
			s[i]='H';
		}
	}
	// 处理W,E
	ave=abs(W-E)/2;
	if(W>E)
	{
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='W'&&cnt<ave)
			{
				cnt++;
				s[i]='H';
			}
		}
	}
	else if(W<E)
	{
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='E'&&cnt<ave)
			{
				cnt++;
				s[i]='H';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='W'||s[i]=='E')
		{
			s[i]='R';
		}
	}
	cout<<s<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}