/*
 * @Author: dsaDadas11
 * @Date: 2025-10-19 20:20:59
 * @LastEditTime: 2025-10-19 20:21:06
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans1=0,ans2=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(ans1>=a[i]) ans1++;
        else ans1--;
    }

    for(int i=n;i>=1;i--)
    {
        if(ans2>=a[i]) ans2++;
        else ans2--;
    }

    cout<<ans1<<' '<<ans2<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}