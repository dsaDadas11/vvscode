/*
 * @Author: dsaDadas11
 * @Date: 2024-01-26 20:21:51
 * @LastEditTime: 2024-01-26 20:22:00
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N],l[N],r[N],sum[N];
stack<int> st;
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	st.push(0);
	for(int i=1;i<=n;i++)
	{
		while(!st.empty()&&a[i]<=a[st.top()]) st.pop();
		l[i]=st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	st.push(n+1);
	for(int i=n;i>=1;i--)
	{
		while(!st.empty()&&a[i]<=a[st.top()]) st.pop();
		r[i]=st.top();
		st.push(i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i]*(sum[r[i]-1]-sum[l[i]]));
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}