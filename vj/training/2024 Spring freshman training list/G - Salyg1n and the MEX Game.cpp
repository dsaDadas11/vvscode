/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-04-17 18:54:37
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int s[N];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+1+n);
	int mex=0;
	for(int i=1;i<=n;i++)
	{
		if(mex==s[i]) ++mex;
		else break;
	}
	cout<<mex<<endl;
	cout.flush();
	int op;
	while(cin>>op)
	{
		if(op<0) break;
		cout<<op<<endl;
		cout.flush();
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}