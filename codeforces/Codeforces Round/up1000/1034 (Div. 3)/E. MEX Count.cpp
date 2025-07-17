/*
 * @Author: dsaDadas11
 * @Date: 2025-07-16 20:12:00
 * @LastEditTime: 2025-07-16 20:12:32
 * @Description: go for it!
 */
/*
 解题思路：
 求每个可能取到的 mex的区间，然后差分前缀和
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    vector<int> cnt(n+2);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    int mex=0;
    while(cnt[mex]) mex++;
    vector<int> d(n+2);
    for(int i=0;i<=mex;i++)
    {
        int l=cnt[i];
        int r=n-i;
        if(l>r)  continue;
        d[l]++,d[r+1]--;
    }
    for(int i=0;i<=n;i++)
    {
        if(i) d[i]+=d[i-1];
        cout<<d[i]<<' ';
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