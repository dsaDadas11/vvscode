/*
 * @Author: dsaDadas11
 * @Date: 2025-07-24 16:14:17
 * @LastEditTime: 2025-07-24 16:14:48
 * @Description: go for it!
 */
/*
 容斥原理，集合的交
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int c[4],n;
int d[4],s;
int f[N];
void init()
{
    f[0]=1;
    for(int i=0;i<4;i++)
    {
        for(int j=c[i];j<N;j++)
        {
            f[j]+=f[j-c[i]];
        }
    }
}
int calc()
{
    int res=0;
    for(int i=1;i<(1<<4);i++)
    {
        int sum=0;
        for(int j=0;j<4;j++)
        {
            if(i&(1<<j)) sum+=c[j]*(d[j]+1);
        }
        int cnt=__builtin_popcount(i);
        if(sum>s) continue;
        if(cnt&1) res+=f[s-sum];
        else res-=f[s-sum];
    }
    return f[s]-res;
}
void solve()
{
    for(int i=0;i<4;i++) cin>>c[i];
    cin>>n;
    init();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++) cin>>d[j];
        cin>>s;
        cout<<calc()<<endl;
    }

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}