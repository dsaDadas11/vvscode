/*
 * @Author: dsaDadas11
 * @Date: 2024-03-28 16:32:36
 * @LastEditTime: 2024-03-28 16:32:46
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
int pre[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	int ave=pre[n]/n;
	bool f=1;
	int yu=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=ave) yu+=a[i]-ave;
		else yu-=ave-a[i];
		if(yu<0)
		{
			f=0;
			break;
		}
	}
	if(f) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}