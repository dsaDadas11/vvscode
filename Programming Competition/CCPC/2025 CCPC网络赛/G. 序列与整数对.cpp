/*
 * @Author: dsaDadas11
 * @Date: 2025-09-23 14:48:27
 * @LastEditTime: 2025-09-23 14:48:37
 * @Description: go for it!
 */
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e5 + 7;
const int inf = 1e18 + 7;

int n,q;
int a[N];
map<pair<int,int>,int> ans;
int cnt[N];
vector<int> mp[N];
int b[N];
map<int,int> now;
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }


    sort(b+1,b+1+n);
    int len=unique(b+1,b+1+n)-b-1;
    // cout<<len<<endl;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(b+1,b+1+len,a[i])-b;
        now[b[a[i]]]=a[i];
        cnt[a[i]]++;
        mp[a[i]].push_back(i);
    }

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<a[i]<<' ';
    // }
    // cout<<endl;


    int x,y;
    while(q--)
    {
        cin>>x>>y;
        x=now[x],y=now[y];
        if(cnt[x]==0||cnt[y]==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(x==y)
        {
            cout<<cnt[x]*(cnt[x]-1)/2<<endl;
            continue;
        }
        if(ans[{x,y}])
        {
            cout<<ans[{x,y}]<<endl;
            continue;
        }

        int res=0;
        if((int)mp[x].size()<(int)mp[y].size())
        {
            for(auto i:mp[x])
            {
                auto tmp=upper_bound(mp[y].begin(),mp[y].end(),i);
                if(tmp==mp[y].end())
                {
                    break;
                }
                int pos=tmp-mp[y].begin();
                res+=(int)mp[y].size()-pos;
            }
            ans[{x,y}]=res;
            ans[{y,x}]=cnt[x]*cnt[y]-res;
            cout<<res<<endl;
        }
        else
        {
            swap(x,y);
            for(auto i:mp[x])
            {
                auto tmp=upper_bound(mp[y].begin(),mp[y].end(),i);
                if(tmp==mp[y].end())
                {
                    break;
                }
                int pos=tmp-mp[y].begin();
                res+=(int)mp[y].size()-pos;
            }
            ans[{x,y}]=res;
            ans[{y,x}]=cnt[x]*cnt[y]-res;
            cout<<ans[{y,x}]<<endl;
        }
    }
}

signed main()
{
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
    return 0;
}