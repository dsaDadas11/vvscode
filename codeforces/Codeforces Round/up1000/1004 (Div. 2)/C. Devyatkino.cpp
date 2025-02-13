/*
 * @Author: HuangCe
 * @Date: 2025-02-13 19:10:32
 * @LastEditTime: 2025-02-13 19:10:58
 * @Description: go for it!
 */
/*
 一看到题解
 我嘞个暴力枚举。。。
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
bool check(int x)
{
    while(x)
    {
        if(x%10==7) return 1;
        x/=10;
    }
    return 0;
}
void solve()
{
    cin>>n;
    int jiu=0;
    int bi=1;
    int ans=1e18;
    for(int i=1;i<=11;i++)
    {
        jiu+=9LL*bi;
        bi*=10LL;
        int t=n;
        for(int j=0;j<=20;j++)
        {
            if(check(t))
            {
                ans=min(ans,j);
                break;
            }
            t+=jiu;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}