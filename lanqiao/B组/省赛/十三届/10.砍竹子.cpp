/*
 * @Author: dsaDadas11
 * @Date: 2025-04-08 19:05:33
 * @LastEditTime: 2025-04-08 19:12:00
 * @Description: go for it!
 */
/*
 很神奇的一个思路

 sqrtf: float
 sqrt: double
 sqrtl: long double
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x;
int ans;
void solve()
{
    cin>>n;
    set<int> pre;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        set<int> now;
        while(x>1)
        {
            now.insert(x);
            if(!pre.count(x)) ans++;
            x=sqrtl(x/2+1);
        }
        pre=now;
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