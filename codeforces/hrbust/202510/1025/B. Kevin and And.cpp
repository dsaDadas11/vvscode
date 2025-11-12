/*
 * @Author: dsaDadas11
 * @Date: 2025-10-26 09:06:46
 * @LastEditTime: 2025-10-26 09:07:12
 * @Description: go for it!
 */
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll

using namespace std;

const int N = 1e5 + 7;
const int inf = 1e16 + 7;
const int mod = 1e9 + 7;

int n, m, k;
int a[N], b[17];
int Cnt[2000];


void init()
{
    for (int i = 1; i < 2000; i++)
    {
        Cnt[i] = __builtin_popcount(i);
    }
}

int tmp[N][17],d[1027];

void solve()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            tmp[i][j]=inf;
        }
    }

    for (int i = 1; i < (1 << m); i++)
    {
        int cnt = 0;
        int res=0;
        for (int j = 0; j < m; j++)
        {
            if (i & (1 << j))
            {
                if(cnt==0) res=b[j+1];
                else res&=b[j+1];
                cnt++;
            }
        }
        if (cnt == 0)
            continue;
        d[i] = res;
    }

    for (int i = 1; i <= n; i++)
    {
        tmp[i][0] = a[i];
        for (int j = 1; j < (1 << m); j++)
        {
            int cnt = Cnt[j];
            tmp[i][cnt] = min(tmp[i][cnt], (a[i] & d[j]));
        }
    }

    vector<int> d2;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            d2.push_back(tmp[i][j] - tmp[i][j - 1]);
        }
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
    }

    sort(d2.begin(), d2.end());

    for (int i = 0; i < k; i++)
    {
        sum += d2[i];
        // cout << d2[i] << ' ';
    }
    // cout << endl;
    cout << sum << endl;
}

signed main()
{
    ios ::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    init();
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
    return 0;
}