/*
 * @Author: dsaDadas11
 * @Date: 2024-03-28 18:33:29
 * @LastEditTime: 2024-03-28 18:33:55
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	cout<<"2430"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
map<int,bool> mp;
map<pair<int,pair<int,int> >,bool> mp2;
void solve()
{
	int n; cin>>n;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			mp[n/i]=1;
			mp[i]=1;
		}
	}
	for(auto i:mp)
	{
		int t1=n/i.first;
		for(auto j:mp)
		{
			if(t1%j.first==0)
			{
				int t2=t1/j.first;
				mp2[{i.first,{j.first,t2}}]=1;
			}
		}
	}
	cout<<mp2.size()<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/