/*
 * @Author: dsaDadas11
 * @Date: 2025-04-10 20:15:45
 * @LastEditTime: 2025-04-10 20:16:35
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n=2021041820210418;
void solve()
{
    vector<int> a;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a.push_back(i);
            if(n/i!=i) a.push_back(n/i);
        }
    }
    int ans=0;
    for(auto x:a)
    {
        for(auto y:a)
        {
            for(auto z:a)
            {
                if(x*y*z==n) ans++;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}