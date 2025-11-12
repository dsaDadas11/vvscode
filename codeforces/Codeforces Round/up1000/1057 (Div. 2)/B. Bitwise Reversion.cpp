/*
 * @Author: dsaDadas11
 * @Date: 2025-11-12 10:59:51
 * @LastEditTime: 2025-11-12 10:59:58
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y,z;
void solve()
{
    cin>>x>>y>>z;

    int a=0,b=0,c=0;
    for(int i=29;i>=0;i--)
    {
        if(x&(1<<i)) // a b
        {
            a|=(1<<i);
            b|=(1<<i);
        }

        if(y&(1<<i))
        {
            b|=(1<<i);
            c|=(1<<i);
        }

        if(z&(1<<i))
        {
            a|=(1<<i);
            c|=(1<<i);
        }
    }

    if((a&b)==x&&(b&c)==y&&(a&c)==z) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}