/*
 * @Author: dsaDadas11
 * @Date: 2024-07-21 14:58:46
 * @LastEditTime: 2024-07-21 20:11:47
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
bool vis[N];
bool cmp(int x,int y)
{
	return x>y;
}
void solve()
{
	int n,x;
	cin>>n>>x;
	for(int i=0;i<=n+2;i++) vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int t=0;
	int j=1;
	int k=1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(a[i]%x) continue;
		t=a[i]/x;
		for(k=j;k<=n;k++)
		{
			if(a[k]>t||vis[k]) continue;
			else break;
		}
		j=k;
		if(a[k]==t&&!vis[k]&&k<=n)
		{
			vis[k]=1;
			vis[i]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		ans++;
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

/*
 更简单的做法

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
int n,x;
void solve()
{
	cin>>n>>x;
	map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+1+n);
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		if(!mp[a[i]]) continue;
		if(!mp[a[i]*x]) continue;
		mp[a[i]]--;
		mp[a[i]*x]--;
		ans-=2;
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
*/