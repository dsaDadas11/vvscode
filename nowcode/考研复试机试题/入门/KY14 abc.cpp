/*
 * @Author: dsaDadas11
 * @Date: 2026-01-19 17:45:23
 * @LastEditTime: 2026-01-19 17:45:29
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
    for(int a=0;a<=9;a++)
    {
        for(int b=0;b<=9;b++)
        {
            for(int c=0;c<=9;c++)
            {
                if(a*100+b*10+c+b*100+c*11==532)
                {
                    cout<<a<<' '<<b<<' '<<c<<endl;
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}