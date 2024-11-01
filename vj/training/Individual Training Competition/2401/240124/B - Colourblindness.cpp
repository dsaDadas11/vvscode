/*
 * @Author: dsaDadas11
 * @Date: 2024-01-24 20:51:43
 * @LastEditTime: 2024-01-24 20:51:56
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
	int n; cin>>n; // G B
	char s[3][107]={'\0'};
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>s[i][j];
			if(s[i][j]=='G') s[i][j]='B';
		}
	}
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		if(s[1][i]!=s[2][i]) flag=0;
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}