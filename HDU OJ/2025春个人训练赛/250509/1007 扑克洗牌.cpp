/*
 * @Author: dsaDadas11
 * @Date: 2025-05-09 18:55:44
 * @LastEditTime: 2025-05-09 18:55:52
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
    for(int i=1;i<=n;i++) cin>>a[i];
    map<int,int> p;
    for(int i=1;i<=n;i++)
    {
        p[a[i]]=i;
    }
    int maxn=1,cnt=1;
    for(int i=1;i<n;i++)
    {
        if(p[i]<p[i+1]) cnt++;
        else
        {
            maxn=max(maxn,cnt);
            cnt=1;
        }
    }
    maxn=max(maxn,cnt);
    cout<<n-maxn<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}