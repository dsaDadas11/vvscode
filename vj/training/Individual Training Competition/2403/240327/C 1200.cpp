/*
 * @Author: dsaDadas11
 * @Date: 2024-03-28 16:33:31
 * @LastEditTime: 2024-03-28 16:33:36
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int s[N],d[N];
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>s[i];
		d[i]=s[i]-s[i-1];
	}
	d[1]=ceil(1.0*s[1]/(n-k+1));
	bool f=1;
	for(int i=2;i<=k;i++)
	{
		if(d[i]<d[i-1])
		{
			f=0;
			break;
		}
	}
	if(f) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}