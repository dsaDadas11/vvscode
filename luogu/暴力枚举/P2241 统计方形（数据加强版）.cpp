/*
 * @Author: dsaDadas11
 * @Date: 2024-10-28 18:50:51
 * @LastEditTime: 2024-10-28 18:54:43
 * @Description: go for it!
 */
// URL: https://www.luogu.com.cn/problem/P2241
/*
 解题思路：
 首先算正方形的个数，手玩一下就能发现规律，
 接着算长方形的个数，我们可以把所有的正方形和长方形都算出来，然后减去正方形的个数，
 那么应该怎么算呢？
 每一个点可以对它这一列后面的每个点产生贡献，也能对这一列底下所有的点产生贡献(延伸成长方形或正方形)，
 然后从每一列开始枚举每一行的每一个点可以产生的贡献，具体公式可以优化，但没必要
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
void solve()
{
	cin>>n>>m;
	int ans1=0,ans2=0;
	for(int i=1;i<=min(n,m);i++)
	{
		ans1+=(n-i+1)*(m-i+1);
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			ans2+=(n-i+1)*(m-j+1);
		}
	}
	cout<<ans1<<' '<<ans2-ans1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}