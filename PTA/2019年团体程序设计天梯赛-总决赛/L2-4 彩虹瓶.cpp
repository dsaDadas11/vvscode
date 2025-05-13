/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 21:44:02
 * @LastEditTime: 2025-04-15 21:44:15
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N];
void solve()
{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	stack<int> q;
	int st=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==st)
		{
			st++;
			while(!q.empty()&&q.top()==st)
			{
				q.pop();
				st++;
			}
		}
		else q.push(a[i]);
		if(q.size()>m) return cout<<"NO"<<endl,void();
	}
	if(!q.empty()) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}