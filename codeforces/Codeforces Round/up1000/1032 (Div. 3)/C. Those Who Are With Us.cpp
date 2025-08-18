/*
 * @Author: dsaDadas11
 * @Date: 2025-08-01 14:32:24
 * @LastEditTime: 2025-08-01 14:32:31
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
void solve()
{
    cin>>n>>m;
    vector<vector<int> > a(n+1,vector<int>(m+1));
    int maxn=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            maxn=max(maxn,a[i][j]);
        }
    }
    map<int,int> row,col;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==maxn)
            {
                row[i]++;
                col[j]++;
                cnt++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(row[i]+col[j]-(a[i][j]==maxn)==cnt)
            {
                cout<<maxn-1<<endl;
                return;
            }
        }
    }
    cout<<maxn<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}