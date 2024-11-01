/*
 * @Author: dsaDadas11
 * @Date: 2024-01-24 11:07:33
 * @LastEditTime: 2024-01-24 11:07:39
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=3e6+7;
const int M=2e3+7;
int a[N],ans[N],stk[N];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	int tt=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		while(tt>0&&a[i]>=a[stk[tt]]) tt--;
		ans[i]=stk[tt];
		stk[++tt]=i;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}