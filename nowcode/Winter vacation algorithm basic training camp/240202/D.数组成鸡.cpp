/*
 * @Author: dsaDadas11
 * @Date: 2024-02-05 12:01:28
 * @LastEditTime: 2024-02-05 12:01:34
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int K=4e4+7;
constexpr int inf=1e9;
void solve()
{
	int n,q; cin>>n>>q;
	map<int,int> cnt;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		cnt[x]++;
	}
	set<int> se{0};
	if(cnt.size()<=18)
	{
		vector<pair<int,int> > v(cnt.begin(),cnt.end());
		int len=v.size();
		for(int i=0;i<len;i++)
		{
			for(int x=v[i].first-K;x<=v[i].first+K;x++)
			{
				int res=1;
				for(int j=0;j<len;j++)
				{
					int y=v[j].first-x;
					if(y==1) continue;
					if(y==-1)
					{
						if(v[j].second%2) res*=-1;
						continue;
					}
					for(int c=1;c<=v[j].second;c++)
					{
						res*=y;
						if(abs(res)>inf) break;
					}
					if(abs(res)>inf) break;
				}
				if(abs(res)<inf) se.insert(res);
			}
		}
	}
	while(q--)
	{
		int m; cin>>m;
		if(se.count(m)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}