/*
 * @Author: dsaDadas11
 * @Date: 2025-03-16 20:50:10
 * @LastEditTime: 2025-03-16 20:50:21
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,q;
int a[N];
int calc(int x)
{
	int sum=0;
	string s=to_string(x);
	for(int i=0;i<s.size();i++)
	{
		sum+=s[i]-'0';
	}
	return sum;
}
void solve()
{
	cin>>n>>q;
	set<int> se;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=10) se.insert(i);
	}
	int op,l,r,x;
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>l>>r;
			auto p=se.lower_bound(l);
			vector<int> v;
			while(p!=se.end()&&*p<=r)
			{
				a[*p]=calc(a[*p]);
				if(a[*p]<10) v.push_back(*p);
				p++;
			}	
			for(auto i:v) se.erase(i);
		}
		else
		{
			cin>>x;
			cout<<a[x]<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}