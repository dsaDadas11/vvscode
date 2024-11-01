/*
 * @Author: dsaDadas11
 * @Date: 2024-08-28 18:45:32
 * @LastEditTime: 2024-08-28 18:45:49
 * @Description: go for it!
 */
//URL:https://codeforces.com/problemset/problem/2002/B
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N],b[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i]) cnt++;
	}
	int cnt2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[n-i+1]) cnt2++;
	}
	if(cnt==n||cnt2==n) cout<<"Bob"<<endl;
	else cout<<"Alice"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}