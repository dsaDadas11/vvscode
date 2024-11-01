/*
 * @Author: dsaDadas11
 * @Date: 2024-05-13 22:17:45
 * @LastEditTime: 2024-05-13 22:17:52
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
pair<int,int> p[N];
bool check(int mid)
{
	int d=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i].second>=mid) continue;
		d+=mid-p[i].second;
	}
	if(d>k) return 0;
	return 1;
}
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	return p1.second>p2.second;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].second;
		p[i].first=i;
	}
	sort(p+1,p+1+n);
	int l=1,r=2e12;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	int min_num=l;
	int ans=0;
	ans+=(min_num-1)*n+1;
	for(int i=n;i>=1;i--)
	{
		if(p[i].second<min_num)
		{
			k-=min_num-p[i].second;
			p[i].second=min_num;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(k==0) break;
		if(p[i].second==l)
		{
			p[i].second++;
			k--;
		}
	}
	for(int i=1;i<=n;i++) p[i].second-=min_num;
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(p[i].second>=1) ans++;
		else break;
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