/*
 * @Author: dsaDadas11
 * @Date: 2025-08-19 14:10:52
 * @LastEditTime: 2025-08-19 14:11:19
 * @Description: go for it!
 */
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N = 2e6 + 7;
constexpr int M = 2e3 + 7;
int n, m, k;
int a[N];
int pos[N];
int power[27];
int tr[N];
int lowbit(int x)
{
	return x & (-x);
}
void add(int p, int x)
{
	for (int i = p; i <= m; i += lowbit(i))
	{
		tr[i] += x;
	}
}
int ask(int p)
{
	int ans = 0;
	for (int i = p; i; i -= lowbit(i))
	{
		ans += tr[i];
	}
	return ans;
}
void init()
{
	power[0] = 1;
	for (int i = 1; i <= 21; i++)
	{
		power[i] = power[i - 1] * 2;
	}
}
bool check(int x, int i, int j)
{
	int h = (i - 1) / power[x];
	int l = h * power[x] + 1;
	int r = (h + 1) * power[x];
	int res = ask(r) - ask(l - 1);
	return k >= res && j >= (r - l + 1);
}
int ans[N];
void solve()
{
	cin >> n >> k;
	m = 1 << n;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i = m; i >= 1; i--)
	{
		int p = pos[i]; // 该球队的位置
		for (int t = n; t >= 0; t--)
		{
			if (check(t, p, i))
			{
				ans[p] = t;
				break;
			}
		}
		add(p, 1);
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int T = 1; // cin>>T;
	while (T--)
	{
		solve();
	}
	return 0;
}