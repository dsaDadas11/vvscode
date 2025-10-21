/*
 * @Author: dsaDadas11
 * @Date: 2025-10-13 16:20:32
 * @LastEditTime: 2025-10-13 16:20:40
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e6+7;
constexpr int M=2e3+7;
int vis[N];
void init()
{
    for(int i=2;i*i<N;i++)
    {
        if(vis[i]) continue;
        for(int j=i*i;j<N;j+=i)
        {
            vis[j]=1;
        }
    }
}
int n;
void solve()
{
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        if(!vis[i])
        {
            cout<<i<<endl;
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}