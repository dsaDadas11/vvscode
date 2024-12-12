/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-12-02 18:14:48
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
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].second; // 生命值
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first; // 伤害
	}
	sort(p+1,p+1+n);
	int sum=k;
	int l=1;
	while(l<=n&&k>0)
	{
		while(p[l].second<=sum&&l<=n) l++;
		if(l>n) break;
		k-=p[l].first;
		if(k<=0)
		{
			cout<<"NO"<<endl;
			return;
		}
		sum+=k;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i].second>sum)
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}