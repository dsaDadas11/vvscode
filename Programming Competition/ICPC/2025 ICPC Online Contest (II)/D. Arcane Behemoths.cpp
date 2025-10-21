/*
 * @Author: dsaDadas11
 * @Date: 2025-09-15 10:03:04
 * @LastEditTime: 2025-09-15 10:03:56
 * @Description: go for it!
 */
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e5 + 7;
const int inf = 1e18 + 7;
const int mod = 998244353;

int fac[N], inv[N], mi2[N];

int ksm(int a, int p)
{
    int res = 1;
    while (p)
    {
        if (p & 1) res = res * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}
void pre()
{
    fac[0] = 1;
    for (int i = 1; i <= N - 2; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[N - 3] = ksm(fac[N - 3], mod - 2);
    for (int i = N - 4; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    mi2[0] = 1;
    for (int i = 1; i <= N - 5; i++)
    {
        mi2[i] = mi2[i - 1] * 2 % mod;
    }
}
int getC(int n, int m)
{
    if (m > n) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int n, ny2;
int a[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;

    // for(int i=1;i<=n;i++)
    // {
    //     ans+=a[i];
    // }

    for (int i = 1; i <= n; i++)
    {
        ans += ((ksm(3, i-1)-1) * ny2 % mod + 1) * a[i] % mod * mi2[n-i];
        ans %= mod;
    }
    cout << ans << '\n';
}

signed main()
{
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pre();
    ny2 = ksm(2, mod - 2);
    int TT = 1;
     cin >> TT;
    while (TT--)
    {
        solve();
    }
    return 0;
}