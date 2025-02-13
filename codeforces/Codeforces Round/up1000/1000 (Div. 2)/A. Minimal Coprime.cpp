/*
 * @Author: dsaDadas11
 * @Date: 2025-01-22 21:37:34
 * @LastEditTime: 2025-01-23 09:27:03
 * @Description: go for it!
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int count = 0;
        if (l <= 1 && 1 <= r) {
            count += 1;
        }
        int a = max(l, 2);
        count += max(0, r - a);
        cout << count << endl;
    }
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
int l,r;
void solve()
{
    cin>>l>>r;
    int ans=0;
    if(l==1) ans++,l++;
    ans+=max(r-l,0LL);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
*/