/*
 * @Author: dsaDadas11
 * @Date: 2024-05-07 19:27:30
 * @LastEditTime: 2024-05-07 19:40:43
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int x,y,z;
	cin>>x>>y>>z;
	int k=x+y-z;
	if(k>max(x,z)) cout<<k<<endl;
	else if(k==0) cout<<z+1<<endl;
	else cout<<"-1"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}