/*
 * @Author: dsaDadas11
 * @Date: 2025-10-27 21:23:42
 * @LastEditTime: 2025-10-27 21:24:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int n;
string s[N];
int ind[N],outd[N];
vector<pair<int,int> > g[N];

int vis[N];
vector<int> ans;
void dfs(int u)
{
    if(ans.size()==n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<s[ans[i]]<<".\n"[i==n-1];
        }
        exit(0);
    }

    for(auto [v,pos]:g[u])
    {
        if(vis[pos]) continue;
        vis[pos]=1;
        ans.push_back(pos);
        dfs(v);
        vis[pos]=0;
        ans.pop_back();
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }

    sort(s+1,s+1+n);

    for(int i=1;i<=n;i++)
    {
        int st=s[i][0]-'a'+1;
        int ed=s[i].back()-'a'+1;

        outd[st]++,ind[ed]++;

        g[st].push_back({ed,i});
    }

    int st=0,ed=0;
    for(int i=1;i<=26;i++)
    {
        if(outd[i]==ind[i]+1)
        {
            if(st) // 有多个起点
            {
                cout<<"***"<<endl;
                return;
            }
            st=i;
        }
        else if(outd[i]+1==ind[i])
        {
            if(ed) // 有多个终点
            {
                cout<<"***"<<endl;
                return;
            }
            ed=i;
        }
        else if(outd[i]!=ind[i])
        {
            cout<<"***"<<endl;
            return;
        }
    }

    if(st==0&&ed==0)
    {
        st=s[1][0]-'a'+1;
    }
    else if((st&&ed)==0)
    {
        cout<<"***"<<endl;
        return;
    }

    dfs(st);

    cout<<"***"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}