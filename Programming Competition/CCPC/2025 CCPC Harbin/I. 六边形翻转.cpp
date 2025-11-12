/*
 * @Author: dsaDadas11
 * @Date: 2025-11-10 16:34:45
 * @LastEditTime: 2025-11-10 16:42:19
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,m;
int x,y,z;
void solve()
{
    cin>>n>>m;

    map<int,int> mpx,mpy,mpz;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        mpx[x]++,mpy[y]++,mpz[z]++;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        mpx[x]++,mpy[y]++,mpz[z]++;
    }

    for(auto [x,y]:mpx)
    {
        if(y%2)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    for(auto [x,y]:mpy)
    {
        if(y%2)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    for(auto [x,y]:mpz)
    {
        if(y%2)
        {
            cout<<"NO"<<endl;
            return;
        }
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