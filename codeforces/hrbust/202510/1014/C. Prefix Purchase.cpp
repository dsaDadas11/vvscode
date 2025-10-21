/*
 * @Author: dsaDadas11
 * @Date: 2025-10-14 21:14:42
 * @LastEditTime: 2025-10-14 21:14:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int inf=1e16;
int n,k;
int c[N];
void solve()
{
    cin>>n;
    vector<int> a(n+5);
    a[0]=inf;
    int minn=inf;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    cin>>k;
    for(int i=n;i>=1;i--)
    {
        minn=min(minn,c[i]);
        c[i]=minn;
    }

    for(int i=1;i<=n;i++)
    {
        if(c[i]==c[i-1])
        {
            a[i]=a[i-1];
        }
        else
        {
            a[i]=min(k/(c[i]-c[i-1]),a[i-1]);
            k-=(c[i]-c[i-1])*a[i];
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}