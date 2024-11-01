/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:50:01
 * @LastEditTime: 2024-01-17 14:50:09
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
struct op
{
	int x,y,sum;
	bool operator<(const op&that)const
	{return sum>that.sum;}
}p[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].x;
	for(int i=1;i<=n;i++) cin>>p[i].y;
	for(int i=1;i<=n;i++) p[i].sum=p[i].x+p[i].y;
	sort(p+1,p+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1) ans+=p[i].x-1;
		else ans-=p[i].y-1;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}