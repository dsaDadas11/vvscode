/*
 * @Author: dsaDadas11
 * @Date: 2025-09-24 11:28:45
 * @LastEditTime: 2025-09-24 11:28:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y;
void solve()
{
    cin>>x>>y;
    int ans=0;
    if(y<2)
    {
        while(x<3)
        {
            if(x==2)
            {
                ans+=2;
                x++;
            }
            else if(x<2)
            {
                ans++;
                x++;
            }
            
        }
    }
    else
    {
        while(x<3)
        {
            ans+=2;
            x++;
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