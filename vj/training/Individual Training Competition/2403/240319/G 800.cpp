/*
 * @Author: dsaDadas11
 * @Date: 2024-03-19 22:47:37
 * @LastEditTime: 2024-03-19 22:48:16
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int ans[N];
struct op
{
	int x,y;
	bool operator<(const op&that ) const
	{
		if(x==that.x) return y>that.y;
		else return x>that.x;
	}
}b[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		b[i]={x,i};
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
		ans[b[i].y]=i;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}