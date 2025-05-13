/*
 * @Author: dsaDadas11
 * @Date: 2025-04-27 15:23:36
 * @LastEditTime: 2025-04-27 15:23:44
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
    string s;
    cin >> s; 
    vector<int> freq(13);
    for (char c : s) {
        freq[c - '0']++;
    }
    string ans = "";
    for (int i = 1; i <= 10; i++)
    {
        int min_req = 10 - i;
        for (int d = min_req; d <= 9; d++)
        {
            if (freq[d] > 0) {
                ans += char('0' + d);
                freq[d]--;
                break; 
            }
        }
    }
    cout << ans << endl; 
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}