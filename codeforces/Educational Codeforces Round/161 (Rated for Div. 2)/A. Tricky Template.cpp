/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-19 12:56:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
void solve()
{
	int n; cin>>n;
	string a,b,c; cin>>a>>b>>c;
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=c[i]&&b[i]!=c[i]) flag=1;
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}