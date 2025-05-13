/*
 * @Author: dsaDadas11
 * @Date: 2025-05-09 19:14:31
 * @LastEditTime: 2025-05-09 19:14:43
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int v,w;
void solve()
{
    cin>>v>>w;
    if(v<=w)
    {
        cout<<"1"<<endl;
        return;
    }
    int cost=w/2+1;
    int ans=v/cost;
    v%=cost;
    if(w-cost<v&&v) ans++;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}