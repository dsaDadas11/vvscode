/*
 * @Author: dsaDadas11
 * @Date: 2024-04-08 22:21:49
 * @LastEditTime: 2024-04-08 22:21:54
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int a[N],n;
void solve()
{
	cout<<fixed<<setprecision(1);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	double ave=1.0*(a[1]+a[n])/2;
	if(ave>a[2]) cout<<1.0*a[2]<<endl;
	else cout<<ave<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}