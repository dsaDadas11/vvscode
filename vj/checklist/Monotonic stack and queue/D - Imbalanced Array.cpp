/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-03-07 14:02:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,ans;
int a[N],l[N],r[N];
stack<int> st;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
        //求a[i]为最大值时区间的左右端点
		while(!st.empty()&&a[i]>=a[st.top()])
		{
			r[st.top()]=i-1;
			st.pop();
		}
		if(!st.empty()) l[i]=st.top()+1;
		else l[i]=1;
		st.push(i);
	}
	while(!st.empty())
	{
		r[st.top()]=n;
		st.pop();
	}
	for(int i=1;i<=n;i++) ans+=a[i]*(i-l[i]+1)*(r[i]-i+1);
	memset(l,0,sizeof l);
	memset(r,0,sizeof r);
	for(int i=1;i<=n;i++)
	{
        //求a[i]为最小值时区间的左右端点
		while(!st.empty()&&a[i]<=a[st.top()])
		{
			r[st.top()]=i-1;
			st.pop();
		}
		if(!st.empty()) l[i]=st.top()+1;
		else l[i]=1;
		st.push(i);
	}
	while(!st.empty())
	{
		r[st.top()]=n;
		st.pop();
	}
	for(int i=1;i<=n;i++) ans-=a[i]*(i-l[i]+1)*(r[i]-i+1);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}