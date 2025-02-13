/*
 * @Author: dsaDadas11
 * @Date: 2024-10-13 15:30:00
 * @LastEditTime: 2024-10-13 15:30:33
 * @Description: go for it!
 */
/*
 解题思路：
 找二进制不相等的最早的那一位就行
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y;
void solve()
{
	cin>>x>>y;
	vector<int> v1,v2;
	while(x)
	{
		v1.push_back(x&1);
		x>>=1;
	}
	while(y)
	{
		v2.push_back(y&1);
		y>>=1;
	}
	for(int i=1;i<=35;i++) v1.push_back(0),v2.push_back(0);
	int ans=1;
	for(int i=0;i<=33;i++)
	{
		if(v1[i]!=v2[i])
		{
			cout<<ans<<endl;
			return;
		}
		ans<<=1;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}