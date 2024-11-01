/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-31 11:57:58
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
pair<int,int> p[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].first;
	for(int i=1;i<=n;i++) cin>>p[i].second;
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++) cout<<p[i].first<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<p[i].second<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}