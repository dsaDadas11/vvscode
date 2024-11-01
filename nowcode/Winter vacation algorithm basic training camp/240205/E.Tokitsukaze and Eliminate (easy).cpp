/*
 * @Author: dsaDadas11
 * @Date: 2024-02-05 19:39:56
 * @LastEditTime: 2024-02-05 19:40:54
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int col[N];
void solve()
{
	int n; cin>>n;
	unordered_map<int,int> num;
	set<int> se;
	for(int i=1;i<=n;i++)
	{
		cin>>col[i];
		num[col[i]]++;
		se.insert(col[i]);
	}
	int len=se.size();
	se.clear();
	int p=0;
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		num[col[i]]--;
		se.insert(col[i]);
		if(num[col[i]]==0) p++;
		if((int)se.size()==len)
		{
			ans++;
			se.clear();
			len-=p;
			p=0;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}