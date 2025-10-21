/*
 * @Author: dsaDadas11
 * @Date: 2025-10-10 15:30:29
 * @LastEditTime: 2025-10-10 15:30:38
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
string s;
void solve()
{
    cin>>n>>k;
    cin>>s;
    s=' '+s;
    int l=1,r=n;
    int cnt=0;
    vector<int> vis(n+1);
    for(int i=1;i<=k;i++)
    {
        if(s[i]=='0')
        {
            vis[l]=1;
            l++;
        }
        else if(s[i]=='1')
        {
            vis[r]=1;
            r--;
        }
        else cnt++;
    }
    
    if(r-l+1>cnt)
    {
        for(int i=l;i<=min(l+cnt-1,r);i++)
        {
            vis[i]=2;
        }
        for(int i=r;i>=max(l,r-cnt+1);i--) vis[i]=2;
    }
    else
    {
        for(int i=l;i<=r;i++) vis[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1) cout<<'-';
        else if(vis[i]==2) cout<<'?';
        else cout<<'+';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}