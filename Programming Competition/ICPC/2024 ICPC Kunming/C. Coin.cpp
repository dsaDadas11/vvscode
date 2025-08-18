/*
 * @Author: dsaDadas11
 * @Date: 2025-08-04 16:36:15
 * @LastEditTime: 2025-08-04 16:36:23
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
void solve()
{
    cin>>n>>k;
    int pos=1,stp=1;
    while(pos<=n)
    {
        if(stp<k)
        {
            // stp相当于轮次，每一轮要淘汰多少人，例如 stp=n/k
            int maxn=min(n,stp*k);
            int add=(maxn-pos)/stp*stp;
            if(add==0) break;
            pos+=add;
            stp++;
        }
        else
        {
            // 该轮将 k-1个人分为 1组，因为第 k个人被去掉了，然后我们计算有多少个被去掉的人
            int add=(pos+k-1-1)/(k-1);
            if(add==0) break;
            if(pos+add<=n) pos+=add;
            else break;
        }
    }
    cout<<pos<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}