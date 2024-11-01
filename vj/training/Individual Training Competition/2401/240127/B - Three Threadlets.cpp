/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-27 21:29:24
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
	int a[5]={0};
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+1+3);
	if(a[1]==a[2]&&a[2]==a[3]) cout<<"YES"<<endl;
	else if(a[2]==a[1]*2&&a[3]==a[1]*3) cout<<"YES"<<endl;
	else if(a[1]==a[2]&&(a[3]==a[1]*2||a[3]==a[1]*3||a[3]==a[1]*4)) cout<<"YES"<<endl;
	else if(a[2]==a[3]&&a[3]==a[1]*2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}