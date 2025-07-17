/*
 * @Author: dsaDadas11
 * @Date: 2025-05-30 19:32:31
 * @LastEditTime: 2025-05-30 19:32:41
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x[3],y[3];
double h(int xx,int yy)
{
    return 30.0*xx+0.5*yy;
}
double h0;
double calc(int xx,int yy)
{
    double th=abs(h0-h(xx,yy)),tm=abs(y[0]-yy);
    th=min(th,360.0-th);
    tm=min(tm,60-tm)*6;
    return th+tm;
}
void solve()
{
    for(int i=0;i<3;i++)
    {
        cin>>x[i]>>y[i];
    }
    h0=h(x[0],y[0]);
    int ansx=0,ansy=0;
    double cost=1e16;
    for(int i=x[1];i<=x[2];i++)
    {
        int st=0,ed=59;
        if(i==x[1]) st=y[1];
        if(i==x[2]) ed=y[2];
        for(int j=st;j<=ed;j++)
        {
            double t=calc(i,j);
            if(cost>t)
            {
                cost=t;
                ansx=i,ansy=j;
            }
        }
    }
    cout<<ansx<<' '<<ansy<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}