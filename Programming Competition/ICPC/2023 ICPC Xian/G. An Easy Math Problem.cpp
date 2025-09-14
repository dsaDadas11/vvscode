/*
 * @Author: dsaDadas11
 * @Date: 2025-08-19 19:12:06
 * @LastEditTime: 2025-08-19 19:12:15
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
void solve()
{
    cin>>n;
    int ans=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i) continue;
        int cnt=0;
        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        ans*=2*cnt+1;
    }
    if(n>1) ans*=3;
    cout<<(ans+1)/2<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}