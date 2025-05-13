/*
 * @Author: dsaDadas11
 * @Date: 2025-04-13 20:05:28
 * @LastEditTime: 2025-04-13 20:06:36
 * @Description: go for it!
 */
/*
 解题思路：
 手算出前四个数的概率(一定要化到最简)
 会发现 pi= (n-i+1)/(n-i+2)
 guess
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
double n;
void solve()
{
    cin>>n;
    cout<<fixed<<setprecision(5);
    cout<<1.0/n;
    for(int i=2;i<=n;i++)
    {
        cout<<" "<<1.0*(n-i+1)/(n-i+2);
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}