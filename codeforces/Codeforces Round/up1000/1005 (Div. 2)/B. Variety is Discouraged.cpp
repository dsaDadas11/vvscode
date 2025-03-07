/*
 * @Author: dsaDadas11
 * @Date: 2025-03-07 17:45:47
 * @LastEditTime: 2025-03-07 17:45:55
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
int a[N],cnt[N],len[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cnt[i]=len[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[a[i]]==1) len[i]=len[i-1]+1;
    }
    int mx=0;
    int l,r;
    for(int i=1;i<=n;i++)
    {
        if(mx<len[i])
        {
            mx=len[i];
            l=i-len[i]+1,r=i;
        }
    }
    if(mx==0) cout<<"0"<<endl;
    else cout<<l<<' '<<r<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}