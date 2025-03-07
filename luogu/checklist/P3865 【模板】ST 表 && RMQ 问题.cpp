/*
 * @Author: HuangCe
 * @Date: 2025-02-25 19:40:52
 * @LastEditTime: 2025-02-25 19:41:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,m;
int a[N],f[N][20];
int lg[N];
void init()
{
    // 避免浮点运算，加快速度
    lg[1]=0;
    for(int i=2;i<=n;i++)
    {
        lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
    }

    for(int i=1;i<=n;i++)
    {
        f[i][0]=a[i];
    }
    for(int j=1;j<20;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r)
{
    int k=lg[r-l+1];
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    init();
    int l,r;
    while(m--)
    {
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}