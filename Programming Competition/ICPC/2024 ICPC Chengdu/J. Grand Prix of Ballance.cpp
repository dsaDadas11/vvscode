/*
 * @Author: dsaDadas11
 * @Date: 2025-07-18 16:47:47
 * @LastEditTime: 2025-07-18 16:47:55
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,q;
struct per
{
    int idx,sco;
    bool operator<(const per&that) const
    {
        if(sco==that.sco) return idx<that.idx;
        return sco>that.sco;
    }
}p[N];
void solve()
{
    cin>>n>>m>>q;
    for(int i=0;i<=m;i++)
    {
        p[i].idx=i,p[i].sco=0;
    }
    vector<int> score(n+1,m);
    int op,idx,x;
    int round=0;
    map<int,int> mp;
    for(int i=1;i<=q;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x;
            round=x;
            mp.clear();
        }
        else if(op==2)
        {
            cin>>idx>>x;
            if(x!=round) continue;
            if(mp[idx]) continue;
            p[idx].sco+=score[x];
            score[x]--;
            mp[idx]++;
        }
        else
        {
            cin>>idx>>x;
            if(x!=round) continue;
            if(mp[idx]) continue;
            mp[idx]++;
        }
    }
    sort(p+1,p+1+m);
    for(int i=1;i<=m;i++)
    {
        cout<<p[i].idx<<' '<<p[i].sco<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}