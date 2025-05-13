/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-04-16 11:40:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int x[N],y[N];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	int xx=0,yy=0,ans=0;
	if(n%2==1)
	{
		xx=x[(n+1)/2];
		yy=y[(n+1)/2];
	}
	else
	{
		xx=(x[n/2]+x[(n+1)/2])/2;
		yy=(y[n/2]+y[(n+1)/2])/2;
	}
	for(int i=1;i<=n;i++)
		{
			ans+=abs(x[i]-xx)+abs(y[i]-yy);
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