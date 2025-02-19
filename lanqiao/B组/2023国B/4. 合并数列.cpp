/*
 * @Author: HuangCe
 * @Date: 2025-02-18 18:45:25
 * @LastEditTime: 2025-02-18 18:45:33
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
int a[N],b[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    int x=0,y=0;
    int suma=0,sumb=0;
    int ans=0;
    
    while(x<=n&&y<=m)
    {
        if(suma==sumb) suma=a[++x],sumb=b[++y];
        else if(suma<sumb) suma+=a[++x],ans++;
        else sumb+=b[++y],ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}