/*
 * @Author: dsaDadas11
 * @Date: 2025-09-11 17:01:44
 * @LastEditTime: 2025-09-11 17:01:52
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
int a[107];
int f[107][107];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=2*i;j++)
        {
            if(n-j-2<=0) continue;
            for(int idx=1;idx<i;idx++)
            {
                int cnt=j-((i-1)-(idx+1)+1);
                if(cnt<0) continue;
                f[i][j]=max(f[i][j],f[idx][cnt]+(a[i]-a[idx])*(a[i]-a[idx]));
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(n-i*2<=2) cout<<(a[n]-a[1])*(a[n]-a[1])<<endl;
        else cout<<f[n][2*i]<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}