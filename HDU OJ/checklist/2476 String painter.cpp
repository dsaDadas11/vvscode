/*
 * @Author: dsaDadas11
 * @Date: 2024-09-12 11:02:56
 * @LastEditTime: 2024-09-13 10:15:10
 * @Description: go for it!
 */
// URL:https://acm.hdu.edu.cn/showproblem.php?pid=2476
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string a,b;
int dp[107][107];
void solve()
{
	int lena=a.size(),lenb=b.size();
	a=' '+a,b=' '+b;
	for(int i=1;i<=lena;i++) dp[i][i]=1;
	for(int r=2;r<=lena;r++)
	{
		for(int l=r-1;l>=1;l--)
		{
			dp[l][r]=1e18;
			if(b[l]==b[r]) dp[l][r]=dp[l+1][r];
			else
			{
				for(int k=l;k<r;k++)
				{
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
	}
	for(int r=1;r<=lena;r++)
	{
		if(a[r]==b[r]) dp[1][r]=dp[1][r-1];
		else
		{
			for(int k=1;k<r;k++)
			{
				dp[1][r]=min(dp[1][r],dp[1][k]+dp[k+1][r]);
			}
		}
	}
	cout<<dp[1][lena]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(cin>>a>>b){solve();}
	return 0;
}