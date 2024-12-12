/*
 * @Author: dsaDadas11
 * @Date: 2024-11-15 21:37:44
 * @LastEditTime: 2024-11-15 21:37:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int ans[N];
int p[30]={0,1,2,2,3,3,4,4,5,5,1,6,6,7,7,8,8,9,9,10,10,11,11,13,12,12,1,13};
void solve()
{
	cin>>n;
	if(n%2==0)
	{
		int cnt=1;
		for(int i=1;i<=n;i+=2)
		{
			cout<<cnt<<' '<<cnt<<' ';
			cnt++;
		}
		cout<<endl;
	}
	else
	{
		if(n<=26) return cout<<"-1"<<endl,void();
		for(int i=0;i<=n+30;i++) ans[i]=0;
		for(int i=1;i<=27;i++) ans[i]=p[i];
		int cnt=14;
		for(int i=28;i<=n;i+=2)
		{
			ans[i]=cnt;
			ans[i+1]=cnt;
			cnt++;
		}
		for(int i=1;i<=n;i++)
		{
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}

}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}