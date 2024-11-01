/*
 * @Author: dsaDadas11
 * @Date: 2024-04-09 14:20:24
 * @LastEditTime: 2024-04-09 14:20:35
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
pair<int,int> p[N];
int x[N],y[N];
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	if(p1.first==p2.first) return p1.second>p2.second;
	else return p1.first<p2.first;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		x[i]=x[i-1]+p[i].first;
		y[i]=y[i-1]+p[i].second;
	}
	double ans=0;
	for(int i=3;i<=n-3;i++)
	{
		double x1=1.0*x[i]/i;
		double y1=1.0*y[i]/i;
		double x2=1.0*(x[n]-x[i])/(n-i);
		double y2=1.0*(y[n]-y[i])/(n-i);
		double s=1.0*abs(x1*y2-x2*y1)/2;
		ans=max(ans,s);
	}
	for(int i=1;i<=n;i++)
	{
		double x1=1.0*p[i].first;
		double y1=1.0*p[i].second;
		double x2=1.0*(x[n]-x1)/(n-1);
		double y2=1.0*(y[n]-y1)/(n-1);
		double s=1.0*abs(x1*y2-x2*y1)/2;
		ans=max(ans,s);
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}