/*
 * @Author: dsaDadas11
 * @Date: 2025-07-25 19:48:48
 * @LastEditTime: 2025-07-25 19:48:55
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=10000007;
int n;
int f[64][64];
int a[64];
int dfs(int pos,bool limit,int cnt)
{
    if(pos==0) return max(cnt,1LL);
    if(!limit&&f[pos][cnt]!=-1) return f[pos][cnt];

    int up=limit?a[pos]:1;
    int res=1;
    for(int i=0;i<=up;i++)
    {
        res*=dfs(pos-1,limit&&i==up,cnt+(i==1));
        res%=mod;
    }

    if(!limit) f[pos][cnt]=res;
    return res;
}
int calc(int x)
{
    int len=0;
    while(x)
    {
        a[++len]=x%2;
        x/=2;
    }
    return dfs(len,1,0);
}
void solve()
{
    memset(f,-1,sizeof f);
    cin>>n;
    cout<<calc(n)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}