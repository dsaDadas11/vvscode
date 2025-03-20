/*
 * @Author: dsaDadas11
 * @Date: 2025-03-07 18:47:11
 * @LastEditTime: 2025-03-07 18:47:18
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
int u,v,w;
void solve()
{
    cin>>n;
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v>>w;
        // 1 u v w
        if((w-v)%u==0) mp[(w-v)/u]++;
        // 2 u w v
        if((v-w)%u==0) mp[(v-w)/u]++;
        // 3 v u w
        if((w-u)%v==0) mp[(w-u)/v]++;
        // 4 v w u
        if((u-w)%v==0) mp[(u-w)/v]++;
        // 5 w u v
        if((v-u)%w==0) mp[(v-u)/w]++;
        // 6 w v u
        if((u-v)%w==0) mp[(u-v)/w]++;

    }
    for(auto [x,y]:mp)
    {
        if(y%n==0&&x>=0) cout<<x<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}