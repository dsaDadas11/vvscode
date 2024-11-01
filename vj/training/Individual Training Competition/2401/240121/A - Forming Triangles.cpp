/*
 * @Author: dsaDadas11
 * @Date: 2024-01-19 12:56:42
 * @LastEditTime: 2024-01-21 21:00:18
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
void solve()
{
    int n; cin>>n;
    int cnt[n+5]={0};
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        cnt[x]++;
    }
    int pre=0;
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        ans+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
        ans+=cnt[i]*(cnt[i]-1)/2*pre;
        pre+=cnt[i];
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