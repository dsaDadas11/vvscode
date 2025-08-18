/*
 * @Author: dsaDadas11
 * @Date: 2025-07-28 16:15:10
 * @LastEditTime: 2025-07-28 16:15:18
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
pair<int,int> h[N];
void solve()
{
    cin>>n>>k;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i].first;
        h[i].second=i;
        mx=max(mx,h[i].first);
    }
    sort(h+1,h+1+n);
    for(int i=1;i<=n;i++)
    {
        if(h[i].second==k)
        {
            k=i;
            break;
        }
    }
    int cnt=0;
    for(int i=k;i<n;i++)
    {
        if(h[i].first==mx)
        {
            cout<<"YES"<<endl;
            return;
        }
        if(cnt+h[i+1].first-h[i].first>h[i].first)
        {
            cout<<"NO"<<endl;
            return;
        }
        cnt+=h[i+1].first-h[i].first;
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}