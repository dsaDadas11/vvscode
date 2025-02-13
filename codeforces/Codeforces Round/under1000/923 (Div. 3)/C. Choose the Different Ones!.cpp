/*
 * @Author: dsaDadas11
 * @Date: 2024-02-07 00:31:38
 * @LastEditTime: 2024-02-07 00:31:48
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N],b[N];
void solve()
{
	int n,m,k; cin>>n>>m>>k;
	map<int,bool> mp1,mp2;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		mp1[x]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int x; cin>>x;
		mp2[x]=1;
	}
	bool flag=1;
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=k;i++)
	{
		if(mp1[i]==1&&mp2[i]==0) cnt1++;
		else if(mp1[i]==0&&mp2[i]==1) cnt2++;
		else if(mp1[i]==1&&mp2[i]==1) cnt3++;
		if(mp1[i]==0&&mp2[i]==0)
		{
			flag=0;
			break;
		}
	}
	bool flag1=0;
	if(cnt1<=k/2&&cnt2<=k/2) flag1=1;
	if(flag&&flag1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}