/*
 * @Author: dsaDadas11
 * @Date: 2024-08-28 22:17:23
 * @LastEditTime: 2024-08-28 22:19:41
 * @Description: go for it!
 */
// URL:https://codeforces.com/contest/570/problem/B
/*
 不知道为什么n为奇且m==zhong时取右边的就不对
 比如 n=3 m=2时 1和 3的取值的可能性不一样？
 有点sb
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
	if(n==1)
	{
		cout<<'1'<<endl;
		return;
	}
	// n为奇数
	if(n%2)
	{
		int zhong=(n+1)/2;
		if(m<zhong) cout<<m+1<<endl;
		else cout<<m-1<<endl; 
	}
	// n为偶数
	else
	{
		int zhong1=n/2;
		int zhong2=n/2+1;
		if(m==zhong1) cout<<zhong2<<endl;
		else if(m==zhong2) cout<<zhong1<<endl;
		else if(m<zhong1) cout<<m+1<<endl;
		else cout<<m-1<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}