/*
 * @Author: dsaDadas11
 * @Date: 2024-08-28 18:29:34
 * @LastEditTime: 2024-08-28 18:29:53
 * @Description: go for it!
 */
// URL:https://codeforces.com/problemset/problem/2002/A
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	cout<<min(n,k)*min(m,k)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}