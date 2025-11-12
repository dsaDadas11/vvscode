/*
 * @Author: dsaDadas11
 * @Date: 2025-11-05 11:38:41
 * @LastEditTime: 2025-11-05 11:38:59
 * @Description: go for it!
 */
/*
 01trie求最大异或对
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int ch[N*31][2],idx; // 深度为 31 [0,30]
void inser(int x)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int j=(x>>i)&1;
        if(!ch[p][j]) ch[p][j]=++idx;
        p=ch[p][j];
    }
}
int query(int x)
{
    int p=0,res=0;
    for(int i=30;i>=0;i--)
    {
        int j=(x>>i)&1;
        if(ch[p][!j]) // 有相反的位
        {
            res+=(1<<i);
            p=ch[p][!j];
        }
        else p=ch[p][j];
    }
    return res;
}

int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        inser(a[i]);
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,query(a[i]));
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