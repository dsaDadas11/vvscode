/*
 * @Author: dsaDadas11
 * @Date: 2025-08-13 20:19:55
 * @LastEditTime: 2025-08-13 20:20:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int l,r;
int a[37],dp[37][67];
int dfs(int pos,bool limit,bool lead0,int cha)
{
    if(pos==0) return cha>=32;
    if(!limit&&!lead0&&dp[pos][cha]!=-1) return dp[pos][cha];

    int up=limit?a[pos]:1;
    int res=0;
    for(int i=0;i<=up;i++)
    {
        res+=dfs(pos-1,limit&&i==up,lead0&&i==0,cha+(i==0?(lead0?0:1):-1));
    }
    if(!limit&&!lead0) dp[pos][cha]=res;
    return res;
}
int calc(int x)
{
    int len=0;
    while(x)
    {
        a[++len]=x%2;
        x>>=1;
    }
    return dfs(len,1,1,32);
}
void solve()
{
    cin>>l>>r;
    memset(dp,-1,sizeof dp);
    cout<<calc(r)-calc(l-1)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}