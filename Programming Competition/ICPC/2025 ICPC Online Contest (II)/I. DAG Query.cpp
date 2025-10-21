/*
 * @Author: dsaDadas11
 * @Date: 2025-09-15 19:32:13
 * @LastEditTime: 2025-09-15 19:52:25
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
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return ans;
}

class Lagrange
{
private:
    vector<ll> x,y;
    vector<ll> inv;

public:
    static constexpr ll mod = 998244353;
    int n;

    Lagrange(const vector<ll>& a,const vector<ll>& b) 
    {
        n = a.size() - 1;
        x.resize(n + 1),y.resize(n + 1);
        inv.resize(n + 1);

        for(int i = 1;i <= n;++i)
        {
            x[i] = (a[i] % mod + mod) % mod;
            y[i] = (b[i] % mod + mod) % mod;
        }

        for(int i = 1;i <= n;++i)
        {
            ll now = 1;
            for(int j = 1;j <= n;++j)
            {
                if(i == j) continue ;
                ll sub = (x[i] - x[j] + mod) % mod;
                now = now * sub % mod;
            }
            inv[i] = quickpow(now,mod - 2ll);
        }
    }

    ll work(ll k) const
    {
        k = (k % mod + mod) % mod;

        vector<ll> pre(n + 1,1),suf(n + 2,1);
        for(int i = 1;i <= n;++i)
        {
            ll v = (k - x[i] + mod) % mod;
            pre[i] = pre[i - 1] * v % mod;
        }
        for(int i = n;i;--i)
        {
            ll v = (k - x[i] + mod) % mod;
            suf[i] = suf[i + 1] * v % mod;
        }

        ll ans = 0;
        for(int i = 1;i <= n;++i)
        {
            ll now = pre[i - 1] * suf[i + 1] % mod;
            now = now * y[i] % mod * inv[i] % mod;
            ans += now;
            ans %= mod;
        }
        return ans;
    }
};

int ask(int s,int t,int c)
{
    cout<<"? "<<s<<' '<<t<<' '<<c<<endl;
    cout.flush();
    int res;
    cin>>res;
    return res;
}

int n,m,k;
void solve()
{
    cin>>n>>m;
    vector<int> x(1001),y(1001);
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
    }

    x[1000]=0,y[1000]=0; // 附加条件
    for(int i=1;i<=999;i++)
    {
        int val=ask(1,n,i);
        x[i]=i,y[i]=val;
    }
    
    cout<<"!"<<endl;
    cout.flush();
    cin>>k;

    Lagrange lag(x,y);
    cout<<lag.work(k)<<endl;
    cout.flush();
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}