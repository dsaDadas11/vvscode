/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-08-22 12:31:34
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e5+7;
constexpr int M=2e3+7;
int a[N];
int sum[N];
void solve()
{
    cout << fixed << setprecision(18);
    int n, pos;
    cin >> n;
    sum[0] = 0;
    int mn = 0x7fffffff;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < mn)
        {
            mn = a[i];
            pos = i;
        }
        sum[i] = sum[i - 1] + a[i];
    }
    long double mx=0.0;
    mx = max({(long double)1.0*(sum[n] - sum[0]) / n, (long double)1.0*(sum[pos + 1] - sum[0]) / (pos + 1), (long double)1.0*(sum[n] - sum[pos - 2]) / (n - pos + 2)});
    cout << mx << endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}