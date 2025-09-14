/*
 * @Author: dsaDadas11
 * @Date: 2025-09-11 20:25:03
 * @LastEditTime: 2025-09-11 20:25:10
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[507][507];
int row[507],col[507];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) row[i]=col[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]<=0)
            {
                ans+=a[i][j];
                row[i]=col[j]=1;
            }
        }
    }

    int res1=0,res2=0;
    for(int i=1;i<=n;i++)
    {
        if(row[i]) continue;
        int minn=1e16;
        for(int j=1;j<=n;j++)
        {
            minn=min(minn,a[i][j]);
        }
        res1+=minn;
    }

    for(int j=1;j<=n;j++)
    {
        if(col[j]) continue;
        int minn=1e16;
        for(int i=1;i<=n;i++)
        {
            minn=min(minn,a[i][j]);
        }
        res2+=minn;
    }

    cout<<ans+min(res1,res2)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}