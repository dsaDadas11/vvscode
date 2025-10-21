/*
 * @Author: dsaDadas11
 * @Date: 2025-09-18 19:35:52
 * @LastEditTime: 2025-09-18 19:36:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int hmod[2]={998244353,1000000007};
int base[2]={29,131};
int p[2][N];
int n,m;
string s,t;
void init()
{
    for(int j=0;j<2;j++)
    {
        p[j][0]=1;
        for(int i=1;i<N;i++)
        {
            p[j][i]=p[j][i-1]*base[j]%mod;
        }
    }
}
int has[2][N],hat[2][N];
int tmp[2];
pair<int,int> get_s(int l,int r)
{
    tmp[0]=tmp[1]=0;
    for(int j=0;j<2;j++)
    {
        tmp[j]=((has[j][r]-has[j][l-1]*p[j][r-l+1]%mod)+mod)%mod;
    }
    return {tmp[0],tmp[1]};
}
pair<int,int> get_t(int l,int r)
{
    tmp[0]=tmp[1]=0;
    for(int j=0;j<2;j++)
    {
        tmp[j]=((hat[j][r]-hat[j][l-1]*p[j][r-l+1]%mod)+mod)%mod;
    }
    return {tmp[0],tmp[1]};
}
void get_ha()
{
    for(int j=0;j<2;j++)
    {
        for(int i=1;i<=n;i++)
        {
            has[j][i]=((has[j][i-1]*base[j]+s[i])%mod+mod)%mod;
        }

        for(int i=1;i<=m;i++)
        {
            hat[j][i]=((hat[j][i-1]*base[j]+t[i])%mod+mod)%mod;
        }
    }
}
int f[N];
int g1[N],g2[N],g3[N];
int suf1[N],suf2[N],suf3[N];
bool check(int ls,int rs,int lt,int rt)
{
    if(rs>n||rt>m) return 0;
    pair<int,int> p1,p2;
    p1=get_s(ls,rs),p2=get_t(lt,rt);
    return p1==p2;
}
void solve()
{
    cin>>s>>t;
    n=s.size(),m=t.size();
    s=' '+s,t=' '+t;
    get_ha();

    // 求出 s和 t的 lcp
    for(int i=1;i<=n;i++)
    {
        int l=0,r=m-1; // -1保证后续 +1能正常进行
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(check(i,i+mid-1,1,mid)) l=mid;
            else r=mid-1;
        }

        f[i]=l+1;

        int j1=i+l+1,j2=l+2;
        if(j1>n||j2>m) continue;
        int l1=0,r1=m;

        while(l1<r1)
        {
            int mid=(l1+r1+1)>>1;
            if(check(j1,j1+mid-1,j2,j2+mid-1)) l1=mid;
            else r1=mid-1;
        }

        f[i]=l+1+l1;
    }

    suf1[n+1]=1;
    for(int i=n;i>=1;i--)
    {
        int l=i+1,r=i+f[i];
        g1[i]=(suf1[l]-suf1[r+1])%mod;
        g2[i]=(suf2[l]-suf2[r+1]+g1[i])%mod;
        g3[i]=(suf3[l]-suf3[r+1]+2*(suf2[l]-suf2[r+1])%mod+suf1[l]-suf1[r+1])%mod;

        suf1[i]=(suf1[i+1]+g1[i])%mod;
        suf2[i]=(suf2[i+1]+g2[i])%mod;
        suf3[i]=(suf3[i+1]+g3[i])%mod;
    }

    cout<<(g3[1]%mod+mod)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}