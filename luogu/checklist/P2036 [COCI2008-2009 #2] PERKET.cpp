/*
 * @Author: dsaDadas11
 * @Date: 2024-10-28 19:51:56
 * @LastEditTime: 2024-10-28 19:52:23
 * @Description: go for it!
 */
/*
 解题思路：
 二进制枚举模板题
*/
// URL: https://www.luogu.com.cn/problem/P2036
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int s[17],b[17];
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>b[i];
	}
	int ans=1e18;
	for(int i=1;i<(1<<n);i++)
	{
		int suan=1,ku=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				suan*=s[j];
				ku+=b[j];
			}
		}
		ans=min(ans,abs(suan-ku));
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}