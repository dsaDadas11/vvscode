/*
 * @Author: dsaDadas11
 * @Date: 2025-11-01 19:49:31
 * @LastEditTime: 2025-11-01 19:49:40
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int l,r,n;
void solve()
{
    cin>>l>>r;
    n=r-l+1;

    vector<int> a(n+5);
    int ans=0;
    
    int pw=1;
    while(pw<=r)
    {
        pw<<=1;
    }

    set<int> se;
    for(int i=l;i<=r;i++) se.insert(i);

    for(int i=r;i>=l;i--)
    {
        while(se.find(pw-i-1)==se.end()) pw>>=1;

        a[i]=pw-i-1;
        se.erase(pw-i-1);
        ans+=i|a[i];
    }

    cout<<ans<<endl;
    for(int i=l;i<=r;i++) cout<<a[i]<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}