/*
 * @Author: dsaDadas11
 * @Date: 2024-04-09 20:49:00
 * @LastEditTime: 2024-04-09 20:50:53
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
int dp[N][4];
//最大最小都不可取  可取最小 可取最大 可取最大最小
int l[N],r[N];
int n,maxn,minn;
void solve()
{
	cin>>n>>minn>>maxn;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		l[i]=max(l[i],minn);
		r[i]=min(r[i],maxn);
		if(l[i]>r[i])
		{
			cout<<"0"<<endl;
			return;
		}
	}
	dp[1][0]=min(r[1],maxn-1)-max(l[1],minn+1)+1;
	if(l[1]==minn) dp[1][1]=1;
	if(r[1]==maxn) dp[1][2]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i][3]=((r[i]-l[i]+1)*dp[i-1][3])%mod;
		dp[i][2]=((r[i]-max(minn+1,l[i])+1)*dp[i-1][2])%mod;
		dp[i][1]=((min(maxn-1,r[i])-l[i]+1)*dp[i-1][1])%mod;
		dp[i][0]=((min(maxn-1,r[i])-max(minn+1,l[i])+1)*dp[i-1][0])%mod;
		if(l[i]==minn)
		{
			dp[i][3]=(dp[i][3]+dp[i-1][2])%mod;
			dp[i][1]=(dp[i][1]+dp[i-1][0])%mod;
		}
		if(r[i]==maxn)
		{
			dp[i][3]=(dp[i][3]+dp[i-1][1])%mod;
			dp[i][2]=(dp[i][2]+dp[i-1][0])%mod;
		}
	}
	cout<<dp[n][3]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}