/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-08-01 15:48:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
string s;
int dp[N][7];   // 第i个位置  lrxhy
void solve()
{
	memset(dp,0,sizeof dp);
	cin>>s;
	int len=s.size();
	s=' '+s;
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=5;j++) dp[i][j]=dp[i-1][j];
		if(s[i]=='l') dp[i][1]+=1; //l
		else if(s[i]=='r') dp[i][2]+=dp[i-1][1]; //lr
		else if(s[i]=='x') dp[i][3]+=dp[i-1][2]; //lrx
		else if(s[i]=='h') dp[i][4]+=dp[i-1][3]; //lrxh
		else if(s[i]=='y') dp[i][5]+=dp[i-1][4]; //lrxhy
		for(int j=1;j<=5;j++) dp[i][j]%=mod;
	}
	cout<<dp[len][5]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}