/*
 * @Author: dsaDadas11
 * @Date: 2025-08-14 11:20:55
 * @LastEditTime: 2025-08-14 11:30:05
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
int dp[13][11][11][2][2][2];
//    pos lst1 lst2 8 4 连续
int a[13];

int dfs(int pos,int lst1,int lst2,bool ei,bool fo,bool conti,bool limit)
{
    if(ei&&fo) return 0;
    if(pos==0) return conti;
    if(!limit&&dp[pos][lst1][lst2][ei][fo][conti]!=-1) return dp[pos][lst1][lst2][ei][fo][conti];

    int up=limit?a[pos]:9;
    int res=0;
    for(int i=0;i<=up;i++)
    {
        res+=dfs(pos-1,lst2,i,ei||i==8,fo||i==4,((lst1==lst2)&&(lst2==i))||conti,limit&&i==up);
    }
    if(!limit) dp[pos][lst1][lst2][ei][fo][conti]=res;
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
    if(len!=11) return 0;
    // dfs中直接判断 lead0无法确定实际长度，我们要保证长度为 11，因此只能这样遍历
    int res=0;
    for(int i=1;i<=a[len];i++)
    {
        res+=dfs(len-1,0,i,i==8,i==4,0,i==a[len]);
    }
    return res;
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