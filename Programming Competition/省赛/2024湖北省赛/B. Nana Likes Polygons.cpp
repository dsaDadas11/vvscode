/*
 * @Author: dsaDadas11
 * @Date: 2025-05-02 14:55:18
 * @LastEditTime: 2025-05-02 14:55:26
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
int x[107],y[107];
double calc(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return 0.5*abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    double ans=1e16;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                double t=calc(x[i],y[i],x[j],y[j],x[k],y[k]);
                if(t>0) ans=min(ans,t);
            }
        }
    }
    if(ans==1e16) cout<<"-1"<<endl;
    else cout<<fixed<<setprecision(12)<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}