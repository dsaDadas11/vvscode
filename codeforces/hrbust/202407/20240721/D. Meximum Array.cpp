/*
 * @Author: dsaDadas11
 * @Date: 2024-07-21 15:57:27
 * @LastEditTime: 2024-07-21 15:57:31
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int a[N];
bool mex[N];
map<int,int> mp;
void solve()
{
	int n;
	cin>>n;
	vector<int> ans;
	memset(mex,0,sizeof mex);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		mex[a[i]]=1;
		while(mex[cnt]) cnt++;
		mp[a[i]]--;
		if(mp[cnt]==0)
		{
			ans.push_back(cnt);
			for(int i=0;i<=cnt;i++) mex[i]=0;
			cnt=0;
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
	{
		cout<<it<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}