/*
 * @Author: dsaDadas11
 * @Date: 2025-01-15 21:15:55
 * @LastEditTime: 2025-01-15 21:16:05
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
string s;
int a[M][M];
int sumr[M],sumc[M];
void solve()
{
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<=n+5;i++) sumr[i]=0;
    for(int i=0;i<=m+5;i++) sumc[i]=0;
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
            sumr[i]+=a[i][j];
        }
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            sumc[j]+=a[i][j];
        }
    }
    int posi=1,posj=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='R')
        {
            a[posi][posj]=-sumc[posj];
            sumc[posj]=0,sumr[posi]+=a[posi][posj];
        }
        else
        {
            a[posi][posj]=-sumr[posi];
            sumr[posi]=0,sumc[posj]+=a[posi][posj];
        }
        if(s[i]=='D') posi++;
        else posj++;
    }
    posi=n,posj=m;
    if(sumr[n]==0)
    {
        a[posi][posj]=-sumc[posj];
        sumc[posj]=0,sumr[posi]+=a[posi][posj];
    }
    else
    {
        a[posi][posj]=-sumr[posi];
        sumr[posi]=0,sumc[posj]+=a[posi][posj];
    }
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