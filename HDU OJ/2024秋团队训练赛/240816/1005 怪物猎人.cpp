/*
 * @Author: dsaDadas11
 * @Date: 2024-08-17 15:31:11
 * @LastEditTime: 2024-08-17 15:31:53
 * @Description: go for it!
 */
/*
 解题思路：看上下界，如果相等则只有一个，否则两个都行
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int k,x,y;
void solve()
{
	cin>>k>>x>>y;
	int l=(k+x-1)/x;
	int r=(k+y-1)/y;
	if(l!=r)
	{
		cout<<"Yes"<<endl;
		cout<<"Yes"<<endl;
	}
	else
	{
		if(l%2)
		{
			cout<<"Yes"<<endl;
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
			cout<<"Yes"<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}