/*
 * @Author: dsaDadas11
 * @Date: 2024-08-22 12:52:06
 * @LastEditTime: 2024-08-22 12:57:54
 * @Description: go for it!
 */
/*
 这道题不能凑0，那我们就凑1
 看这样一个序列： -1 -1 2 -1 2 -1 2 1 是可行的
 把它一般化可变成 a1 -1 2 -1 2 -1 2.....-1 2 a2n
 求和可得 -a1-2*(n-2)+2*a2n
 求积得   a1*a2n
 两者相等，并令a1=1可求得 a2n=2*n-3 因此序列就出来了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
void solve()
{
	cin>>n;
	cout<<"1 ";
	for(int i=1;i<n;i++)
	{
		cout<<"-1 2 ";
	}
	cout<<2*n-3<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}