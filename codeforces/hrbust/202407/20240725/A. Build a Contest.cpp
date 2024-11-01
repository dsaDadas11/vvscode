/*
 * @Author: dsaDadas11
 * @Date: 2024-07-25 20:39:43
 * @LastEditTime: 2024-07-25 21:03:46
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
int cnt[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	int num=0;
	for(int i=1;i<=m;i++)
	{
		if(!cnt[a[i]])
		{
			cnt[a[i]]++;
			num++;
			if(num==n)
			{
				cout<<"1";
				for(int j=1;j<=n;j++)
				{
					cnt[j]--;
					if(!cnt[j]) num--;
				}
			}
			else cout<<"0";
		}
		else
		{
			cnt[a[i]]++;
			cout<<"0";
		}
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
更简便的ac代码
用到 mp.erase(key);

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N];
map<int,int> mp;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		mp[a[i]]++;
		if(mp.size()==n)
		{
			cout<<"1";
			for(int j=1;j<=n;j++)
			{
				mp[j]--;
				if(mp[j]==0) mp.erase(j);
			}
		}
		else cout<<"0";
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/