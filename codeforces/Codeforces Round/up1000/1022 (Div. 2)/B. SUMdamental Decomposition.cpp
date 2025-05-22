/*
 * @Author: dsaDadas11
 * @Date: 2025-05-18 11:32:53
 * @LastEditTime: 2025-05-18 11:34:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x;
void solve()
{
    cin>>n>>x;
    if(n==1)
    {
        if(x==0) cout<<"-1"<<endl;
        else cout<<x<<endl;
        return;
    }

    int c=__builtin_popcount(x);

    if (c >= n) {
        std::cout << x << "\n";
    } else {
        if ((n - c) % 2 == 0) {
            std::cout << n + x - c << "\n";
        } else {
            if (c == 0) {
                std::cout << n - 1 + 4 << "\n";
            } else if (c == 1) {
                if (x == 1) {
                    std::cout << n - 1 + 4 << "\n";
                } else {
                    std::cout << n + x - c + 1 << "\n";
                }
            } else {
                std::cout << n + x - c + 1 << "\n";
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}