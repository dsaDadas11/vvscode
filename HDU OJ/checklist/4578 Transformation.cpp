/*
 * @Author: dsaDadas11
 * @Date: 2025-10-01 21:27:51
 * @LastEditTime: 2025-10-02 11:37:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=10007;
int n,m;
struct Tree
{
    int l,r,len;
    int sum1,sum2,sum3;
    int add,mul,st; // 加 乘 置数
} t[N<<2];
void build(int rt,int l,int r)
{
    t[rt]={l,r,r-l+1,0,0,0,0,1,0};
    if(l==r) return;
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void pushup(int rt) // 向上传递
{
    t[rt].sum1=(t[ls].sum1+t[rs].sum1)%mod;
    t[rt].sum2=(t[ls].sum2+t[rs].sum2)%mod;
    t[rt].sum3=(t[ls].sum3+t[rs].sum3)%mod;
}
void pushdown(int rt) // 下放标记
{
    if(t[rt].st) // 置数优先级比 add,mul低
    {
        t[ls].add=0,t[ls].mul=1,t[ls].st=t[rt].st;
        t[rs].add=0,t[rs].mul=1,t[rs].st=t[rt].st;

        t[ls].sum1=t[ls].st*t[ls].len%mod;
        t[ls].sum2=t[ls].st*t[ls].st%mod*t[ls].len%mod;
        t[ls].sum3=t[ls].st*t[ls].st%mod*t[ls].st%mod*t[ls].len%mod;

        t[rs].sum1=t[rs].st*t[rs].len%mod;
        t[rs].sum2=t[rs].st*t[rs].st%mod*t[rs].len%mod;
        t[rs].sum3=t[rs].st*t[rs].st%mod*t[rs].st%mod*t[rs].len%mod;

        t[rt].st=0;
    }

    int c=t[rt].add,a=t[rt].mul;
    t[ls].add=(t[ls].add*a%mod+c)%mod,t[rs].add=(t[rs].add*a%mod+c)%mod;
    t[ls].mul=t[ls].mul*a%mod,t[rs].mul=t[rs].mul*a%mod;

    t[ls].sum3=(a*a%mod*a%mod*t[ls].sum3%mod+3*a*a%mod*c%mod*t[ls].sum2%mod+3*a*c%mod*c%mod*t[ls].sum1%mod+c*c%mod*c*t[ls].len%mod)%mod;
    t[ls].sum2=(a*a%mod*t[ls].sum2%mod+2*a*c%mod*t[ls].sum1%mod+c*c%mod*t[ls].len%mod)%mod;
    t[ls].sum1=(a*t[ls].sum1%mod+c*t[ls].len%mod)%mod;

    t[rs].sum3=(a*a%mod*a%mod*t[rs].sum3%mod+3*a*a%mod*c%mod*t[rs].sum2%mod+3*a*c%mod*c%mod*t[rs].sum1%mod+c*c%mod*c*t[rs].len%mod)%mod;
    t[rs].sum2=(a*a%mod*t[rs].sum2%mod+2*a*c%mod*t[rs].sum1%mod+c*c%mod*t[rs].len%mod)%mod;
    t[rs].sum1=(a*t[rs].sum1%mod+c*t[rs].len%mod)%mod;

    t[rt].add=0,t[rt].mul=1;
}
void change(int rt,int l,int r,int op,int x)
{
    if(t[rt].l>r||t[rt].r<l) return;
    if(l<=t[rt].l&&t[rt].r<=r)
    {
        if(op==1)
        {
            t[rt].add=(t[rt].add+x)%mod;
            int a=1,c=x;
            t[rt].sum3=(a*a%mod*a%mod*t[rt].sum3%mod+3*a*a%mod*c%mod*t[rt].sum2%mod+3*a*c%mod*c%mod*t[rt].sum1%mod+c*c%mod*c*t[rt].len%mod)%mod;
            t[rt].sum2=(a*a%mod*t[rt].sum2%mod+2*a*c%mod*t[rt].sum1%mod+c*c%mod*t[rt].len%mod)%mod;
            t[rt].sum1=(a*t[rt].sum1%mod+c*t[rt].len%mod)%mod;
        }
        else if(op==2)
        {
            t[rt].add=t[rt].add*x%mod,t[rt].mul=t[rt].mul*x%mod;
            int a=x,c=0;
            t[rt].sum3=(a*a%mod*a%mod*t[rt].sum3%mod+3*a*a%mod*c%mod*t[rt].sum2%mod+3*a*c%mod*c%mod*t[rt].sum1%mod+c*c%mod*c*t[rt].len%mod)%mod;
            t[rt].sum2=(a*a%mod*t[rt].sum2%mod+2*a*c%mod*t[rt].sum1%mod+c*c%mod*t[rt].len%mod)%mod;
            t[rt].sum1=(a*t[rt].sum1%mod+c*t[rt].len%mod)%mod;
        }
        else
        {
            t[rt].st=x;
            t[rt].add=0,t[rt].mul=1;
            t[rt].sum1=x*t[rt].len%mod;
            t[rt].sum2=x*x%mod*t[rt].len%mod;
            t[rt].sum3=x*x%mod*x%mod*t[rt].len%mod;
        }
        return;
    }

    pushdown(rt);
    int mid=(t[rt].l+t[rt].r)>>1;
    if(l<=mid) change(ls,l,r,op,x);
    if(mid+1<=r) change(rs,l,r,op,x);
    pushup(rt); 
}
int query(int rt,int l,int r,int p)
{
    if(t[rt].r<l||t[rt].l>r) return 0;
    if(l<=t[rt].l&&t[rt].r<=r)
    {
        if(p==1) return t[rt].sum1;
        else if(p==2) return t[rt].sum2;
        else return t[rt].sum3;
    }
    pushdown(rt);
    return (query(ls,l,r,p)+query(rs,l,r,p))%mod;
}
void solve()
{
    int op,x,y,c;
    build(1,1,n);
    while(m--)
    {
        cin>>op>>x>>y>>c;
        if(op==4) cout<<query(1,x,y,c)<<endl;
        else change(1,x,y,op,c);
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(cin>>n>>m&&n&&m){solve();}
    return 0;
}