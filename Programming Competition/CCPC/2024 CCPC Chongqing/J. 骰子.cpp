/*
 * @Author: dsaDadas11
 * @Date: 2025-01-12 11:30:37
 * @LastEditTime: 2025-01-12 11:31:35
 * @Description: go for it!
 */
/*
 解题思路：
 列下草稿模拟一下过程可以知道，只要有2*2的大小就能将格内所有数印成6
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
void solve()
{
    cin>>n>>m;
    cout<<n*m*6<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}