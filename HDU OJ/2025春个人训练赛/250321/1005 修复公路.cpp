/*
 * @Author: dsaDadas11
 * @Date: 2025-03-21 18:52:29
 * @LastEditTime: 2025-03-21 18:52:39
 * @Description: go for it!
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
int fa[N];
int find_fa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}
void merge_set(int x,int y)
{
    int fax=find_fa(x);
    int fay=find_fa(y);
    fa[fax]=fay;
}
void init()
{
    for(int i=1;i<=n+3;i++) fa[i]=i;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    for(int i=1;i<=n;i++)
    {
        int li=i-a[i];
        int ri=i+a[i];
        if(li>=1) merge_set(li,i);
        if(ri<=n) merge_set(i,ri);
    }
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        mp[find_fa(i)]++;
    }
    cout<<mp.size()-1<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}