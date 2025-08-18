/*
 * @Author: dsaDadas11
 * @Date: 2025-07-28 19:48:54
 * @LastEditTime: 2025-07-28 19:50:37
 * @Description: go for it!
 */
/*
 解题思路：
 因为电梯向下走不耗电，因此我们可以先让电梯往上到最高点，然后依次接送 r最大的客户
 在上升至最高点的途中，我们能接送尽量接送 (保证 now一定会不减)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,f;
struct op
{
    int l,r,idx;
}a[N];
bool cmp1(op x,op y)
{
    if(x.l==y.l) return x.r>y.r;
    return x.l<y.l;
}
bool cmp2(op x,op y)
{
    return x.r>y.r;
}
void solve()
{
    cin>>n>>f;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r;
        a[i].idx=i;
    }
    sort(a+1,a+1+n,cmp1);
    int now=f,ans=0;
    vector<int> res;
    vector<op> b;
    for(int i=1;i<=n;i++)
    {
        auto [l,r,idx]=a[i];
        if(l<=now&&r>=now)
        {
            ans+=r-l;
            now=r;
            res.push_back(idx);
            continue;
        }
        if(l>now)
        {
            ans+=r-now;
            now=r;
            res.push_back(idx);
            continue;
        }
        b.push_back(a[i]);
    }
    sort(b.begin(),b.end(),cmp2);
    for(auto [l,r,idx]:b)
    {
        ans+=r-l;
        res.push_back(idx);
    }
    cout<<ans<<endl;
    for(auto i:res) cout<<i<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}