/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:51:50
 * @LastEditTime: 2024-01-17 14:51:57
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
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		sum+=x;
	}
	if((int)sqrt(sum)*(int)sqrt(sum)==sum) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}