/*
 * @Author: dsaDadas11
 * @Date: 2025-03-09 19:32:28
 * @LastEditTime: 2025-03-09 19:33:19
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,len,sum;
int a[N],cnt[N];
int ans1[N],ans2[N];
struct op
{
    int l,r,idx;
    bool operator<(const op&that) const
    {
        if((l-1)/len!=(that.l-1)/len) return l<that.l;
        if(((l-1)/len+1)&1) return r<that.r;
        return r>that.r;
    }
}q[N];
void add(int x)
{
    sum+=cnt[x];
    cnt[x]++;
}
void del(int x)
{
    cnt[x]--;
    sum-=cnt[x];
}
void solve()
{
    cin>>n>>m;
    len=sqrt(n);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].idx=i;
    }
    sort(q+1,q+1+m);
    for(int i=1,l=1,r=0;i<=m;i++)
    {
        while(q[i].l<l) add(a[--l]);
        while(r<q[i].r) add(a[++r]);
        while(l<q[i].l) del(a[l++]);
        while(q[i].r<r) del(a[r--]);
        
        if(q[i].l==q[i].r)
        {
            ans1[q[i].idx]=0,ans2[q[i].idx]=1;
            continue;
        }
        ans1[q[i].idx]=sum,ans2[q[i].idx]=(r-l+1)*(r-l)/2;
        int g=gcd(ans1[q[i].idx],ans2[q[i].idx]);
        ans1[q[i].idx]/=g,ans2[q[i].idx]/=g;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans1[i]<<"/"<<ans2[i]<<endl;
    }

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}