/*
 * @Author: dsaDadas11
 * @Date: 2025-04-08 18:22:07
 * @LastEditTime: 2025-04-08 18:22:18
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dx[17]={0,1,0,-1,1,1,-1,-1};
int dy[17]={1,0,-1,0,1,-1,1,-1};
int n,m;
int a[107][107];
int ans[107][107];
bool check(int x,int y)
{
    return x<1||x>n||y<1||y>m;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j])
            {
                ans[i][j]=9;
                continue;
            }
            for(int k=0;k<8;k++)
            {
                int xx=i+dx[k];
                int yy=j+dy[k];
                if(!check(xx,yy)&&a[xx][yy]) ans[i][j]++;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}