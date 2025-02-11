/*
 * @Author: dsaDadas11
 * @Date: 2025-01-18 20:28:02
 * @LastEditTime: 2025-01-18 20:28:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
char a[5][N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[1][i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[2][i];
    }
    int minn=1,maxn=n;
    for(int i=1;i<n;i++)
    {
        if(a[2][i]=='0'&&a[1][i+1]=='1')
        {
            maxn=i;
            break;
        }
    }
    for(int i=1;i<maxn;i++)
    {
        if(a[2][i]=='1'&&a[1][i+1]=='0')
        {
            minn=i+1;
        }
    }
    for(int i=1;i<=minn;i++) cout<<a[1][i];
    for(int i=minn;i<=n;i++) cout<<a[2][i];
    cout<<endl;
    cout<<maxn-minn+1<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}