/*
 * @Author: dsaDadas11
 * @Date: 2025-04-27 15:38:06
 * @LastEditTime: 2025-04-27 15:38:27
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int m = n - k;
    int l = (m + 1) / 2;
    int lf = a[l - 1];
    int rt = a[n - l];
    int ans = rt - lf + 1;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
    	std::cin >> a[i];
    }

    std::sort(a.begin(),a.end());
    int l = (n- k - 1) / 2, r = (n + k + 1) / 2;

    std::cout << a[r] - a[l] + 1 << "\n";
}


signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
*/