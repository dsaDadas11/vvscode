/*
 * @Author: dsaDadas11
 * @Date: 2025-07-28 18:51:46
 * @LastEditTime: 2025-07-28 18:52:12
 * @Description: go for it!
 */
/*
 解题思路：
 二分答案即可，边界判断出了点问题，，
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
int p[N];
bool check(int x)
{
    vector<int> cnt(n);
    for(int i=1;i<=x;i++)
    {
        cnt[(p[i]-1)/m]++;
    }
    for(int i=0;i<n;i++)
    {
        if(cnt[i]+k>=m) return 0;
    }
    return 1;
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n*m;i++) cin>>p[i];
    int l=m,r=n*m;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<l<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}