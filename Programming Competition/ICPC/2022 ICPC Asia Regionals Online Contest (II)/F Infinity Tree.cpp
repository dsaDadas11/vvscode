/*
 * @Author: dsaDadas11
 * @Date: 2025-09-10 20:30:12
 * @LastEditTime: 2025-09-10 20:30:31
 * @Description: go for it!
 */
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e5 + 7;
const int inf = 1e18 + 7;
const int mod = 1e9 + 7;

int k,x,y;
__int128_t p[N];

void solve()
{
    cin>>k>>x>>y;

    p[0]=1;
    int len=0;
    for(int i=1;i;i++)
    {
        p[i]=p[i-1]*(1+k);
        len=i;
        if(p[i]>=inf)
        {
            len--;
            break;
        }
    }

    while(x!=y)
    {
        if(x<y) swap(x,y);
        int l=0,r=len;
        if(x==1)
        {
            cout<<1<<endl;
            return;
        }
        for(int i=0;i<=len;i++)
        {
            if(p[i]>=x)
            {
                l=i-1;
                break;
            }
        }
        if(x>=p[len])
        {
            l=len;
        }
        x=(x-p[l]+k-1)/k;
    }

    cout<<x<<endl;
}

signed main()
{
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
     cin >> TT;
    while (TT--)
    {
        solve();
    }
    return 0;
}