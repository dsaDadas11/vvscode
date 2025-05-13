/*
 * @Author: dsaDadas11
 * @Date: 2025-04-27 16:02:20
 * @LastEditTime: 2025-04-27 16:09:32
 * @Description: go for it!
 */
/*
 解题思路：
 思维题，首先 cnt[ai]>=4 肯定可以
 当 cnt[ai]<4 && cnt[ai]>=2 时 (以 2为例)
 我们可以将 ai+1, ai+2 天调成 10, 00
 那么 ai+2 天只剩一种 1的情况，如果 1才是正确的话，
 那么我们可在 ai+1 天猜 ai+2 ai+3 天，因为我们已经知道 ai+2 为 1，那么可以猜 10
 如果 ai+3 错了的话，可以在 ai+2 天猜 ai+3 ai+4 天，然后依次类推 (这些都是 cnt[a]==1的情况，只能猜一次)
 当 cnt[aj]>=2 时，因为我们已经知道了 aj+1 的答案，因此我们可以猜测 aj+2 为 0/1,总有一种情况是对的

 综上 cnt>=4可以 或者 
     cnt[i]>=2,cnt[j]>=2 并且 [i+1,j-1] 全都是大于等于 1的
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
void solve()
{
    cin>>n;
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    for(auto [x,y]:mp)
    {
        if(y>=4) return cout<<"Yes"<<endl,void();
    }
    vector<pair<int,int> > p(mp.begin(),mp.end());
    for(int i=0;i<p.size();i++)
    {
        if(p[i].second>=2)
        {
            int j;
            for(j=i+1;j<p.size();j++)
            {
                if(p[j].first!=p[j-1].first+1) break;
                if(p[j].second>=2) return cout<<"Yes"<<endl,void();
            }
            i=j-1;
        }
    }
    cout<<"No"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}