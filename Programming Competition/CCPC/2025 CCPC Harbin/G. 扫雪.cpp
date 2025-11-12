/*
 * @Author: dsaDadas11
 * @Date: 2025-11-11 19:33:45
 * @LastEditTime: 2025-11-11 19:36:44
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n,m;
int h[M][M];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>h[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        queue<int> q;
        for(int j=m;j>=1;j--)
        {
            if(h[i][j]<0)
            {
                q.push(j);
                continue;
            }
            while(!q.empty()&&h[i][j]>0)
            {
                int ed=q.front();
                int mm=min(h[i][j],-h[i][ed]);
                h[i][j]-=mm,h[i][ed]+=mm;
                if(h[i][ed]==0) q.pop();
            }
        }

        if(i==n) continue;
        for(int j=1;j<=m;j++)
        {
            if(h[i][j]>0)
            {
                h[i+1][j]+=h[i][j];
                h[i][j]=0;
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans+=abs(h[i][j]);
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