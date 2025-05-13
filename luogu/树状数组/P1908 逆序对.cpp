/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:40
 * @LastEditTime: 2025-01-11 18:49:18
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,ans;
int a[N],tr[N],b[N];
int lowbit(int x)
{
    return (x&(-x));
}
void add(int p,int val)
{
    for(int i=p;i<=n;i+=lowbit(i))
    {
        tr[i]+=val;
    }
}
int ask(int p)
{
    int sum=0;
    for(int i=p;i;i-=lowbit(i))
    {
        sum+=tr[i];
    }
    return sum;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    int len=unique(b+1,b+1+n)-(b+1);
    //cout<<"len: "<<len<<endl;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(b+1,b+1+n,a[i])-b;
        //cout<<"a[i]: "<<a[i]<<endl;
    }
    for(int i=n;i>=1;i--)
    {
        add(a[i],1);
        ans+=ask(a[i]-1);
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