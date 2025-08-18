/*
 * @Author: dsaDadas11
 * @Date: 2025-07-25 19:27:32
 * @LastEditTime: 2025-07-25 19:27:45
 * @Description: go for it!
 */
/*
 改改范围能把加强版过了，提高+的难度。。。
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int l,r;
int f[12][20];
int a[12];
int dfs(int pos,bool limit,bool lead0,int last)
{
    if(pos==0) return 1;
    if(!limit&&!lead0&&f[pos][last]!=-1) return f[pos][last];

    int up=limit?a[pos]:9;
    int res=0;
    for(int i=0;i<=up;i++)
    {
        if(abs(i-last)<2) continue;
        if(lead0) res+=dfs(pos-1,limit&&i==up,lead0&&i==0,i==0?12:i);
        else res+=dfs(pos-1,limit&&i==up,lead0&&i==0,i);
    }
    if(!limit&&!lead0) f[pos][last]=res;
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
    return dfs(len,1,1,12);
}
void solve()
{
    memset(f,-1,sizeof f);
    cin>>l>>r;
    cout<<calc(r)-calc(l-1)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}