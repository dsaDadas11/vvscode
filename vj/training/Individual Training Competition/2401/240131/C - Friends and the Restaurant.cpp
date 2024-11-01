/*
 * @Author: dsaDadas11
 * @Date: 2024-02-01 11:39:43
 * @LastEditTime: 2024-02-01 11:39:49
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int a[N],b[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		b[i]=x-a[i];
	}
	sort(b+1,b+1+n);
	int cnt=0;
	for(int i=1,j=n;i<j;i++,j--)
	{
		while(i<j&&b[i]+b[j]<0) i++;
		if(i<j) cnt++;
	}
	cout<<cnt<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}