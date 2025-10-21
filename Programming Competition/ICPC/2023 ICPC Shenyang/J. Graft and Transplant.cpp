/*
 * @Author: dsaDadas11
 * @Date: 2025-09-24 12:19:30
 * @LastEditTime: 2025-09-24 12:21:02
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
int d[N];
void solve()
{
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        d[u]++,d[v]++;
    }

    if(n==2)
    {
        cout<<"Bob"<<endl;
        return;
    }

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==1) cnt++;
    }
    cnt--; // 一个节点当根节点

    if(cnt==n-1)
    {
        cout<<"Bob"<<endl;
        return;
    }
    
    if((n-1-cnt)&1)
    {
        cout<<"Bob"<<endl;
    }
    else cout<<"Alice"<<endl;

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}