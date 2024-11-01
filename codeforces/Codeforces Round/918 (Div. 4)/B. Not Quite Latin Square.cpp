/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:51:33
 * @LastEditTime: 2024-01-17 14:51:40
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
void solve()
{
	char mp[5][5]={'\0'};
	int px=0;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>mp[i][j];
			if(mp[i][j]=='?')
			{
				px=i;
			}
		}
	}
	bool flag1=0,flag2=0,flag3=0;
	for(int i=1;i<=3;i++)
	{
		if(mp[px][i]=='A') flag1=1;
		if(mp[px][i]=='B') flag2=1;
		if(mp[px][i]=='C') flag3=1;
	}
	if(flag1==0) cout<<"A"<<endl;
	if(flag2==0) cout<<"B"<<endl;
	if(flag3==0) cout<<"C"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}