/*
 * @Author: dsaDadas11
 * @Date: 2024-03-16 16:25:44
 * @LastEditTime: 2024-03-16 16:25:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,k;
pair<int,int> p[N]; // 1,2
void pre()
{
	p[1]={1,0};
	p[2]={0,1};
	for(int i=3;i<=N;i++)
	{
		p[i].first=p[i-1].first+p[i-2].first;
		p[i].second=p[i-1].second+p[i-2].second;
	}
}
void solve()
{
	cin>>n>>k;
	if(k>=100)
	{
		cout<<"0"<<endl;
		return;
	}
	int a=p[k].first,b=p[k].second;
	int ans=0;
	for(int i=0;i<=n/b;i++)
	{
		if(((n-b*i)%a==0)&&i>=(n-b*i)/a) ans++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}