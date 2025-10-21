/*
 * @Author: dsaDadas11
 * @Date: 2025-09-19 16:27:53
 * @LastEditTime: 2025-09-19 16:28:03
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
void solve()
{
    cin>>n;
    int ans=0;
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]&1) v.push_back(a[i]);
        else ans+=a[i];
    }
    if(v.size()==0)
    {
        cout<<0<<endl;
        return;
    }

    bool ok=1;
    sort(v.begin(),v.end());
    int r=v.size()-1,l=0;
    while(l<=r)
    {
        if(ok)
        {
            ans+=v[r];
            ok=0;
            r--;
        }
        else
        {
            l++;
            ok=1;
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