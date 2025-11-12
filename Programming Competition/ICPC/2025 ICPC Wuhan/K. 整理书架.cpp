/*
 * @Author: dsaDadas11
 * @Date: 2025-11-04 21:34:14
 * @LastEditTime: 2025-11-04 21:34:26
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int inf=1e12;
int n;
int a[N],b[N];
set<int> posa[N],posb[N];
int cost;
vector<pair<int,int> > ans;
void swap_set(int i)
{
    posa[a[i]].erase(i);
    posa[b[i]].insert(i);
    posb[b[i]].erase(i);
    posb[a[i]].insert(i);
    ans.push_back({i,i});
    swap(a[i],b[i]);
}
void calc(int i)
{
    auto pos1=posa[b[i]].upper_bound(i);
    auto pos2=posb[b[i]].upper_bound(i);

    if(pos1!=posa[b[i]].end()&&pos2!=posb[b[i]].end())
    {
        if(abs(*pos1-i)<abs(*pos2-i))
        {
            int j=*pos1;
            swap_set(j);
            cost+=abs(j-i);
            ans.push_back({i,j});
            // a
            posa[a[i]].erase(i);
            posa[b[j]].insert(i);
            // b
            posb[b[j]].erase(j);
            posb[a[i]].insert(j);
            swap(a[i],b[j]);
        }
        else
        {
            int j=*pos2;
            cost+=abs(j-i);
            ans.push_back({i,j});
            // a
            posa[a[i]].erase(i);
            posa[b[j]].insert(i);
            // b
            posb[b[j]].erase(j);
            posb[a[i]].insert(j);
            swap(a[i],b[j]);
        }
    }
    else if(pos1!=posa[b[i]].end())
    {
        int j=*pos1;
        swap_set(j);
        cost+=abs(j-i);
        ans.push_back({i,j});
        // a
        posa[a[i]].erase(i);
        posa[b[j]].insert(i);
        // b
        posb[b[j]].erase(j);
        posb[a[i]].insert(j);
        swap(a[i],b[j]);
    }
    else if(pos2!=posb[b[i]].end())
    {
        // cout<<"look: "<<i<<endl;
        int j=*pos2;
        cost+=abs(j-i);
        ans.push_back({i,j});
        // a
        posa[a[i]].erase(i);
        posa[b[j]].insert(i);
        // b
        posb[b[j]].erase(j);
        posb[a[i]].insert(j);
        swap(a[i],b[j]);
    }
}
void solve()
{
    cin>>n;
    cost=0;
    ans.clear();
    for(int i=1;i<=n;i++)
    {
        posa[i].clear();
        posb[i].clear();
    }

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        posa[a[i]].insert(i);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        posb[b[i]].insert(i);
    }

    for(int i=1;i<=n;i++)
    {
        int len=posa[i].size()+posb[i].size();
        if(len&1)
        {
            cout<<-1<<endl;
            return;
        }
    }
    
    // 把 a[i]变成 b[i]
    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i]) continue;
        // swap(a[i],b[j])
        // 交换 a[i]
        auto pos1=posa[b[i]].upper_bound(i);
        auto pos2=posb[b[i]].upper_bound(i);

        int c1=inf;
        if(pos1!=posa[b[i]].end()) c1=min(c1,abs(i-*pos1));
        if(pos2!=posb[b[i]].end()) c1=min(c1,abs(i-*pos2));

        // 交换 b[i]
        auto pos3=posa[a[i]].upper_bound(i);
        auto pos4=posb[a[i]].upper_bound(i);

        int c2=inf;
        if(pos3!=posa[a[i]].end()) c2=min(c2,abs(i-*pos3));
        if(pos4!=posb[a[i]].end()) c2=min(c2,abs(i-*pos4));

        if(c1==inf&&c2==inf)
        {
            // cout<<"look: "<<endl;
            cout<<-1<<endl;
            return;
        }

        if(c1<c2)
        {
            // cout<<"i: "<<i<<endl;
            calc(i);
        }
        else
        {
            swap_set(i);
            calc(i);
        }
    }

    cout<<cost<<' '<<ans.size()<<endl;
    for(auto [x,y]:ans)
    {
        cout<<x<<' '<<y<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}