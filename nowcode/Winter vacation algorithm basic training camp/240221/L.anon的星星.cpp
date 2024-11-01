/*
 * @Author: dsaDadas11
 * @Date: 2024-02-21 18:40:17
 * @LastEditTime: 2024-02-21 18:40:24
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
	int n,x; cin>>n>>x;
    int a1=(x+n)/2;
    int a2=(n-x)/2;
    if(a1+a2!=n||a1-a2!=x) cout<<"-1"<<endl;
    else cout<<a1<<' '<<a2<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}