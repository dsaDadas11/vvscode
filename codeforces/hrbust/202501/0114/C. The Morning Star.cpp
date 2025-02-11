/*
 * @Author: dsaDadas11
 * @Date: 2025-01-14 21:03:02
 * @LastEditTime: 2025-01-15 11:42:58
 * @Description: go for it!
 */
/*
 解题思路：
 第一种情况：行和列相等 直接 mp[x]++统计即可
 第二种情况：斜线，那么有 y=x+m1 或者 y=-x+m2 可以观察到一条线上的截距是相等的，
            因此我们记录 mp[y-x] mp[x+y] 即可
 要注意情况的总数为 mp*(mp-1)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
void solve()
{
    cin>>n;
    vector<pair<int,int> > p(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    map<int,int> row,col,l,r;
    for(int i=1;i<=n;i++)
    {
        row[p[i].first]++;
        col[p[i].second]++;
        l[p[i].first-p[i].second]++;
        r[p[i].second+p[i].first]++;
    }
    int ans=0;
    for(auto [x,y]:row)
    {
        if(y>1) ans+=y*(y-1);
    }
    for(auto [x,y]:col)
    {        
        if(y>1) ans+=y*(y-1);
    }
    for(auto [x,y]:l)
    {
        if(y>1) ans+=y*(y-1);
    }
    for(auto [x,y]:r)
    {
        if(y>1) ans+=y*(y-1);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}