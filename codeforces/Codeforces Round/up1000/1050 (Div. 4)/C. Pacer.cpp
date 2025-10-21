/*
 * @Author: dsaDadas11
 * @Date: 2025-09-19 11:01:19
 * @LastEditTime: 2025-09-19 11:01:26
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
int a[N],b[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    int st=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int d=a[i]-a[i-1];
        if(st!=b[i]) ans+=((d%2)?d:d-1);
        else ans+=((d%2)?d-1:d);
        st=b[i];
    }
    ans+=(m-a[n]);
    cout<<ans<<endl;

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}