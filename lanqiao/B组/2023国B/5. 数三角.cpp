/*
 * @Author: HuangCe
 * @Date: 2025-02-18 19:25:11
 * @LastEditTime: 2025-02-18 19:25:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
using pll=pair<int,int>;
int n;
pll p[N];
long double dist(pll x,pll y)
{
    return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}
bool check(pll x,pll y,pll z) // 判断三点共线
{
    if(x.first==y.first||y.first==z.first||x.first==z.first) return (x.first==y.first)&&(x.first==z.first)&&(y.first==z.first);
    int k1=(x.second-y.second)*(x.first-z.first);
    int k2=(x.second-z.second)*(x.first-y.first);
    return k1==k2;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        map<long double,vector<int> > mp;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            mp[dist(p[i],p[j])].push_back(j);
        }

        for(auto [d,v]:mp)
        {
            for(int a=0;a<v.size();a++)
            {
                for(int b=a+1;b<v.size();b++)
                {
                    if(!check(p[i],p[v[a]],p[v[b]]))
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}