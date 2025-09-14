/*
 * @Author: dsaDadas11
 * @Date: 2025-09-08 21:40:24
 * @LastEditTime: 2025-09-09 10:55:45
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
pair<int,int> p[N];

void solve()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        cin>>p[i].first>>p[i].second;
    }    
    sort(p+1,p+1+m);

    priority_queue<int,vector<int>,greater<int> > pq;
    int now=1,ans=n;
    int r=0;
    while(now<=m||!pq.empty())
    {
        if(pq.empty()&&now<=m)
        {
            r=p[now].first;
        }
        while(now<=m)
        {
            if(p[now].first<=r)
            {
                pq.push(p[now].second);
                now++;
            }
            else break;
        }
        int t=pq.top();
        pq.pop();
        if(t>r)
        {
            ans--;
            r++;
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
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int m,n;
void solve()
{
    cin>>m>>n;
    int l,r;
    map<int,vector<int> > mp;
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        mp[l].push_back(r);
    }
    vector<pair<int,vector<int> > > g(mp.begin(),mp.end());

    int ans=n;
    multiset<int> se;
    for(int i=0;i<g.size();i++)
    {
        auto [l,vec]=g[i];
        int nxtl=(i+1==g.size())?n:g[i+1].first;

        for(auto r:vec) se.insert(r);

        for(int j=l;j<nxtl;j++)
        {
            while(!se.empty()&&*se.begin()<=j) se.erase(se.begin());
            if(se.empty()) break;
            ans--;
            se.erase(se.begin());
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
*/