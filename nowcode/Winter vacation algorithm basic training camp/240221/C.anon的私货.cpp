/*
 * @Author: dsaDadas11
 * @Date: 2024-02-21 18:38:36
 * @LastEditTime: 2024-02-21 18:38:58
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
    a[0]=a[n+1]=1e18;
	for(int i=1;i<=n+1;i++)
    {
        int l=min(a[i],a[i-1])-1;
        ans+=l;
        a[i]-=l;
        a[i-1]-=l;
    }
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}