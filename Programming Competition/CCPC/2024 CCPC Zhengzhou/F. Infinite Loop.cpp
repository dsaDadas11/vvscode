/*
 * @Author: dsaDadas11
 * @Date: 2025-08-07 15:17:03
 * @LastEditTime: 2025-08-07 15:17:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,k,q;
int a[N],b[N],st[N],ed[N],s;
void solve()
{
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        a[i+n]=a[i]+k;
        b[i+n]=b[i];
        s+=b[i];
    }

    for(int i=1;i<=2*n;i++)
    {
        st[i]=max(ed[i-1]+1,a[i]);
        ed[i]=st[i]+b[i]-1;
    }

    int x,y;
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        int h=0;
        if(s<=k)
        {
            if(x==1) h=ed[y];
            else if(x==2) h=ed[y+n];
            else h=ed[y+n]+k*(x-2);
        }
        else
        {
            if(x==1) h=ed[y];
            else if(x==2) h=ed[y+n];
            else h=ed[y+n]+s*(x-2);
        }
        int ansd=h/k+1,ansh=h%k;
        if(ansh==0) ansd--,ansh=k;
        cout<<ansd<<' '<<ansh<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}