/*
 * @Author: dsaDadas11
 * @Date: 2024-02-18 19:23:15
 * @LastEditTime: 2024-02-18 19:23:22
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
    int n,x; cin>>n;
    for(int i=1;i<=n;i++) cin>>x;
    if(n%2) cout<<"qcjj"<<endl;
    else cout<<"zn"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
    while(T--){solve();}
	return 0;
}