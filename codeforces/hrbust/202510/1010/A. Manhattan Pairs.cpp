/*
 * @Author: dsaDadas11
 * @Date: 2025-10-10 19:44:44
 * @LastEditTime: 2025-10-10 20:28:11
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
array<int,3> p[N];
struct op1
{
    int x,y;
    int pos;
    bool operator<(const op1&a) const
    {
        if(y==a.y) return x>a.x;
        return y>a.y;
    }
} p1[N];
struct op2
{
    int x,y;
    int pos;
    bool operator<(const op2&a) const
    {
        if(y==a.y) return x<a.x;
        return y<a.y;
    }
} p2[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i][0]>>p[i][1];
        p[i][2]=i;
    }
    sort(p+1,p+1+n);
    int m1=0,m2=0;
    for(int i=1;i<=n/2;i++) p2[++m2]={p[i][0],p[i][1],p[i][2]};
    for(int i=n/2+1;i<=n;i++) p1[++m1]={p[i][0],p[i][1],p[i][2]};
    sort(p1+1,p1+1+m1);
    sort(p2+1,p2+1+m2);

    // int ans=0;
    // for(int i=1;i<=n/2;i++)
    // {
    //     ans+=abs(p1[i].x-p[i].first)+abs(p1[i].y-p[i].second);
    // }
    // cout<<ans<<endl;
    for(int i=1;i<=n/2;i++)
    {
        cout<<p1[i].pos<<' '<<p2[i].pos<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}