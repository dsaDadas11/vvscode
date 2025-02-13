/*
 * @Author: HuangCe
 * @Date: 2025-02-12 13:13:42
 * @LastEditTime: 2025-02-12 13:16:21
 * @Description: go for it!
 */
/*
 解题思路：
 首先看哪些情况不成立，
 当 n和 m都小于 k时永远不会使子串的值变为 k
 对于整个字符串 n+m来看，如果 n,m相差大于 k，那么整个串的值一定大于 k
 排除了这些情况后，我们就按 k个 0和 k个 1划分
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
void solve()
{
    cin>>n>>m>>k;
    if(n<k&&m<k) return cout<<"-1"<<endl,void();
    if(abs(n-m)>k) return cout<<"-1"<<endl,void();
    if(m>n)
    {
        for(int i=1;i<=min(m,k);i++) cout<<"1";
        m-=k;
    }
    while(n>0)
    {
        for(int i=1;i<=min(n,k);i++) cout<<"0";
        n-=k;
        if(m>0)
        {
            for(int i=1;i<=min(m,k);i++) cout<<"1";
            m-=k;
        }
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