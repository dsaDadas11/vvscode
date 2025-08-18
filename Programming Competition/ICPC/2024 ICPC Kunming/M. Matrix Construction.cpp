/*
 * @Author: dsaDadas11
 * @Date: 2025-08-03 11:54:14
 * @LastEditTime: 2025-08-03 11:54:21
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
void solve()
{
    cin>>n>>m;
    vector<vector<int> > a(n+1,vector<int>(m+1));
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]) continue;
            int x=i,y=j;
            while(x>=1&&x<=n&&y>=1&&y<=m)
            {
                a[x][y]=cnt++;
                x+=1,y-=1;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}