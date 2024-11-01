/*
 * @Author: dsaDadas11
 * @Date: 2024-08-03 09:40:16
 * @LastEditTime: 2024-08-03 09:40:21
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b,c;
int lowbit(int x)
{
	return x&(-x);
}
void solve()
{
	cin>>a>>b>>c;
	if(lowbit(a)==lowbit(b)&&lowbit(b)==lowbit(c)) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}