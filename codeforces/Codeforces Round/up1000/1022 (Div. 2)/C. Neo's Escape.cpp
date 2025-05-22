/*
 * @Author: dsaDadas11
 * @Date: 2025-05-18 13:52:15
 * @LastEditTime: 2025-05-18 13:52:23
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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b;
    b.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1]) b.push_back(a[i]);
    }
    int ans=1;
    for(int i=1;i+1<b.size();i++)
    {
        if(b[i-1]>b[i]&&b[i]<b[i+1]) ans++;
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