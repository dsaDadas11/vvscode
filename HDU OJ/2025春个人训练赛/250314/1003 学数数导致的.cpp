/*
 * @Author: dsaDadas11
 * @Date: 2025-03-15 11:07:29
 * @LastEditTime: 2025-03-15 11:07:58
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
int suf[N]; // 记大于 0的后缀种类数
int cnt[N];
int zer[N];
vector<int> v[N];
bool vis[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v[a[i]].clear();
        cnt[a[i]]=0;
        vis[a[i]]=0;
    }
	for(int i=0;i<=n+5;i++) suf[i]=zer[i]=0;
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1];
		if(a[i]==0) continue;
		if(cnt[a[i]]==0) suf[i]++;
		cnt[a[i]]++;
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) continue;
		v[a[i]].push_back(i);
	}

	// 找 0位置
    for(int i=n;i>=1;i--)
    {
        zer[i]=zer[i+1];
        if(a[i]==0) zer[i]=i;
    }

	for(int i=1;i<=n;i++)
	{
		// 找 0
		if(a[i]==0) continue;
		if(vis[a[i]]) continue;
		int pos=zer[i];
		if(pos==0) continue;
		
		auto p=lower_bound(v[a[i]].begin(),v[a[i]].end(),pos);
		if(p!=v[a[i]].end())
		{
			ans+=suf[*p+1];
			vis[a[i]]=1;
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