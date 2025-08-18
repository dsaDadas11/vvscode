/*
 * @Author: dsaDadas11
 * @Date: 2025-08-11 11:43:20
 * @LastEditTime: 2025-08-11 11:52:38
 * @Description: go for it!
 */
/*
 解题思路：
 拓扑排序，将所有的关键点算出来，然后经过这个关键点的其他点与这个点连上边，
 关键点的意思是：其他与它有关的点必须经过它，
 因此我们可以从非关键点经过拓扑走向关键点
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,c,x;
void solve()
{
    cin>>n>>m;
    vector<vector<int> > p(n+1);
    vector<int> imp(m+1);
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        while(c--)
        {
            cin>>x;
            imp[x]=i;
            p[i].push_back(x);
        }
    }
    set<int,greater<int> > g[n+1];
    vector<int> ind(n+1);
    for(int i=n;i>=1;i--)
    {
        for(auto x:p[i])
        {
            if(imp[x]!=i&&!g[i].count(imp[x]))
            {
                g[i].insert(imp[x]);
                ind[imp[x]]++;
            }
        }
    }

    vector<int> q[2];
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0) q[0].push_back(i);
    }
    int idx=0;
    while(ans.size()<n)
    {
        sort(q[idx].begin(),q[idx].end(),greater<int>());
        for(auto u:q[idx])
        {
            ans.push_back(u);
            for(auto v:g[u])
            {
                ind[v]--;
                if(ind[v]==0) q[!idx].push_back(v);
            }
        }
        q[idx].clear();
        idx=!idx;
    }
    int cnt=1;
    bool flag=0;
    for(auto i:ans)
    {
        if(i!=cnt++)
        {
            flag=1;
            break;
        }
    }
    if(!flag) cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i];
            if(i!=ans.size()-1) cout<<" ";
        }
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}