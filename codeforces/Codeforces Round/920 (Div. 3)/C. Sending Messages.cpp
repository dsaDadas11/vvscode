/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:59:09
 * @LastEditTime: 2024-01-17 14:59:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int m[N];
void solve()
{
	int n,f,a,b; cin>>n>>f>>a>>b;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
		tot+=min((m[i]-m[i-1])*a,b);
	}
	if(tot<f) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}