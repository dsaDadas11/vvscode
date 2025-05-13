/*
 * @Author: dsaDadas11
 * @Date: 2025-04-26 10:24:52
 * @LastEditTime: 2025-04-26 10:25:31
 * @Description: go for it!
 */
/*
 以为是左下角开始。。。实际上是左上角
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n,m,k;
int a[M][M];
int cnt[M<<1];
void solve()
{
    cin>>n>>m>>k;
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int l=-1,r=m;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(cnt[a[i][j]]==0) sum++;
            cnt[a[i][j]]++;
        }
        if(sum==k)
        {
            l=i;
            break;
        }
    }
    if(l==-1) return cout<<"0"<<endl,void();
    int ans=0;
    for(;l<=n;l++)
    {
        while(sum==k&&r>=1)
        {
            for(int i=1;i<=l;i++)
            {
                cnt[a[i][r]]--;
                if(cnt[a[i][r]]==0) sum--;
            }
            r--;
        }
        ans+=m-r;

        for(int j=1;j<=r;j++)
        {
            if(cnt[a[l+1][j]]==0) sum++;
            cnt[a[l+1][j]]++;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}