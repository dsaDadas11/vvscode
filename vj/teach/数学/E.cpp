/*
 * @Author: dsaDadas11
 * @Date: 2025-10-11 19:53:33
 * @LastEditTime: 2025-10-11 19:53:40
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
    vector<pair<int,int> > ans;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i) continue;
        int cnt=0;
        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        ans.push_back({i,cnt});
    }
    if(n>1) ans.push_back({n,1});

    for(auto [x,y]:ans)
    {
        for(int i=1;i<=y;i++) cout<<x<<' ';
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