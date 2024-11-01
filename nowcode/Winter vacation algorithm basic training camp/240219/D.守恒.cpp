/*
 * @Author: dsaDadas11
 * @Date: 2024-02-19 18:22:07
 * @LastEditTime: 2024-02-19 18:22:12
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
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int ans=0;
    for(int i=1;i<=sum/n;i++)
    {
        if(sum%i==0) ans++;
    }
    if(n==1) ans=1;
    cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}