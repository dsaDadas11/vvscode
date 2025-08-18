/*
 * @Author: dsaDadas11
 * @Date: 2024-09-03 14:44:18
 * @LastEditTime: 2024-09-03 14:57:13
 * @Description: go for it!
 */
/*
 需要初始化边界
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string a,b;
int dp[M][M];
void solve()
{
	cin>>a>>b;
	int lena=a.size(),lenb=b.size();
	a=' '+a,b=' '+b;
	
	// 初始化
	for(int i=1;i<=lena;i++) dp[i][0]=i; // 将A全删除
	for(int i=1;i<=lenb;i++) dp[0][i]=i; // 将A全插入B

	for(int i=1;i<=lena;i++)
	{
		for(int j=1;j<=lenb;j++)
		{
			if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
			else
			{
				//               删除        插入       替换
				dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
			}
		}
	}
	cout<<dp[lena][lenb]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}