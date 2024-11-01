/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-26 17:29:56
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,ans[N];
pair<int,int> p[N];
stack<int> st;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	for(int i=1;i<=n;i++)
	{
		while(!st.empty()&&p[i].first>=p[st.top()].first)
		{
			ans[i]+=p[st.top()].second;
			st.pop();
		}
		if(!st.empty())
		{
			ans[st.top()]+=p[i].second;
		}
		st.push(i);
	}
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,ans[i]);
	cout<<res<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}