/*
 * @Author: dsaDadas11
 * @Date: 2025-03-28 19:44:02
 * @LastEditTime: 2025-03-28 19:44:17
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,q;
int a[N],tr[N];
int lowbit(int x)
{
    return x&(-x);
}
void add(int p,int x)
{
    for(int i=p;i<=n;i+=lowbit(i))
    {
        tr[i]+=x;
    }
}
int sum(int p)
{
    int ans=0;
    for(int i=p;i;i-=lowbit(i))
    {
        ans+=tr[i];
    }
    return ans;
}
void solve()
{
    cin>>n>>q;
    for(int i=0;i<=n+3;i++) tr[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        add(i,a[i]);
    }
    int ans=0;
    int cnt=1;
    int op,x,y;
    for(int i=1;i<=q;i++)
    {
        cin>>op>>x>>y;
        if(op==1)
        {
            add(x,y-a[x]);
            a[x]=y;
        }
        else
        {
            ans^=(sum(y)/100-sum(x-1)/100)*cnt;
            cnt++;
            //cout<<sum(y)/100-sum(x-1)/100<<endl;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}