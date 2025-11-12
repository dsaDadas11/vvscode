/*
 * @Author: dsaDadas11
 * @Date: 2025-11-05 22:13:51
 * @LastEditTime: 2025-11-05 22:49:29
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int one=(1<<30)-1;
int calc(int x)
{
    return 31-__builtin_clz(x);
}
int ask(int c)
{
    cout<<"? "<<c<<endl;
    cout.flush();
    int res;
    cin>>res;
    return res;
}
int n;
set<int> se;
void dfs(int l,int r)
{
    if(l>=r||se.size()==n) return;

    // 找最大
    int k=calc(l^r);

    int high_mask=one^((1<<(k+1))-1);
    int low_mask=(1<<k)-1;

    int ck=1,clow=0;
    int c=((l&high_mask)^high_mask)|(ck<<k);
    int res=ask(c);
    int l_max=res^c;
    se.insert(l_max);

    if(se.size()==n) return;

    c=((l&high_mask)^high_mask)|low_mask;
    res=ask(c);
    int r_min=res^c;
    se.insert(r_min);

    if(se.size()==n) return;

    dfs(l,l_max);
    if(se.size()==n) return;

    dfs(r_min,r);
    if(se.size()==n) return;
}
void solve()
{
    se.clear();
    cin>>n;

    int maxn=ask(0);
    int minn=ask(one)^one;
    se.insert(maxn);
    se.insert(minn);

    dfs(minn,maxn);

    cout<<"! ";
    for(auto i:se) cout<<i<<' ';
    cout<<endl;
    cout.flush();
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}