/*
 * @Author: dsaDadas11
 * @Date: 2025-07-25 15:47:20
 * @LastEditTime: 2025-07-25 15:47:49
 * @Description: go for it!
 */
/*
 数位dp板子题
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int f[20][200];
int a[20];
int dfs(int pos,bool limit,int sum)
{
    if(pos==0) return sum;
    if(!limit&&f[pos][sum]!=-1) return f[pos][sum];

    int up=limit?a[pos]:9;
    int res=0;
    for(int i=0;i<=up;i++)
    {
        res+=dfs(pos-1,limit&&i==a[pos],sum+i);
        res%=mod;
    }

    if(!limit) f[pos][sum]=res;
    return res;
}
int calc(int x)
{
    int len=0;
    while(x)
    {
        a[++len]=x%10;
        x/=10;
    }
    return dfs(len,1,0);
}
void solve()
{
    int l,r;
    cin>>l>>r;
    memset(f,-1,sizeof f);
    cout<<((calc(r)-calc(l-1))%mod+mod)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}