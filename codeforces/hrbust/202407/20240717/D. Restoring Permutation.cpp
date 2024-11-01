/*
 * @Author: dsaDadas11
 * @Date: 2024-07-17 15:52:41
 * @LastEditTime: 2024-07-17 15:52:47
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int b[N];
bool vis[N];
void solve()
{
	int n;
	cin>>n;
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		if(b[i]==2*n)
		{
			cout<<"-1"<<endl;
			return;
		}
		vis[b[i]]=1;
	}
	if(!vis[1])
	{
		cout<<"-1"<<endl;
		return;
	}
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		v.push_back(b[i]);
		for(int j=b[i]+1;j<=2*n;j++)
		{
			if(vis[j]) continue;
			vis[j]=1;
			v.push_back(j);
			break;
		}
		if((int)v.size()%2)
		{
			cout<<"-1"<<endl;
			return;
		}
	}
	for(int i=0;i<(int)v.size();i++) cout<<v[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}