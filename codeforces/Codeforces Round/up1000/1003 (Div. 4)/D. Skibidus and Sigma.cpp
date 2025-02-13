/*
 * @Author: HuangCe
 * @Date: 2025-02-11 19:41:39
 * @LastEditTime: 2025-02-11 19:42:53
 * @Description: go for it!
 */
/*
 解题思路：
 列草稿可以发现 a,b两个数组互换位置影响的大小与 suma,sumb 有关
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
struct op
{
    int idx;
    int sum;
    bool operator<(const op&that) const
    {
        return sum>that.sum;
    }
}b[N];
void solve()
{
    cin>>n>>m;
    vector<vector<int> > a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        b[i].idx=i;
        int s=0;
        for(int j=1;j<=m;j++)
        {
            s+=a[i][j];
        }
        b[i].sum=s;
    }
    sort(b+1,b+1+n);
    int ans=0;
    int cnt=n*m;
    for(int i=1;i<=n;i++)
    {
        int idx=b[i].idx;
        for(int j=1;j<=m;j++)
        {
            ans+=cnt*a[idx][j];
            cnt--;
        }
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