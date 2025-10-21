/*
 * @Author: dsaDadas11
 * @Date: 2025-10-08 20:15:05
 * @LastEditTime: 2025-10-08 20:45:28
 * @Description: go for it!
 */
/*
 无向图中：
 欧拉路：只有两个点的度为奇数 (起点和终点)，其余都为偶数
 欧拉回路：度数都为偶数
 上述判断完之后，图可能不是连通的，我们可以先用 dfs跑到终点或起点，然后再跑一遍图

 有向图：
 除起点和终点外的所有点出度与入度相等，起点的 out比 int大 1，终点的 in比 out大 1

 说好的卡 map呢。。不过 pd_ds库的 hash确实快
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e6+7;
constexpr int M=2e3+7;
int n;
string s1,s2;
map<string,int> mp;
vector<int> g[N];
int st;
int vis[N];
void dfs(int u)
{
    vis[u]=1;
    st=u;
    for(auto v:g[u])
    {
        if(vis[v]) continue;
        vis[v]=1;
        dfs(v);
    }
}
void solve()
{
    while(cin>>s1>>s2)
    {
        if(!mp.count(s1)) mp[s1]=++n;
        if(!mp.count(s2)) mp[s2]=++n;
        g[mp[s1]].push_back(mp[s2]);
        g[mp[s2]].push_back(mp[s1]);
    }

    vector<int> cnt(2,0);
    for(int i=1;i<=n;i++)
    {
        cnt[(int)g[i].size()&1]++;
    }
    if(cnt[1]!=2&&cnt[1]!=0) // 可能是欧拉路，也可能是欧拉回路
    {
        cout<<"Impossible"<<endl;
        return;
    }

    dfs(1);
    for(int i=1;i<=n;i++) vis[i]=0;
    dfs(st);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout<<"Impossible"<<endl;
            return;
        }
    }
    cout<<"Possible"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}

/*
并查集写法：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string s1,s2;
map<string,int> mp;
int fa[N];
int d[N];
int find_fa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}
bool merge_set(int x,int y)
{
    int fax=find_fa(x),fay=find_fa(y);
    if(fax==fay) return 0;
    fa[fax]=fay;
    return 1;
}
void solve()
{
    int cnt=0;
    for(int i=1;i<N;i++) fa[i]=i;
    while(cin>>s1>>s2)
    {
        if(!mp.count(s1)) mp[s1]=++n;
        if(!mp.count(s2)) mp[s2]=++n;
        d[mp[s1]]++,d[mp[s2]]++;
        if(merge_set(mp[s1],mp[s2])) cnt++;
    }

    // if(n==0) // sb特殊样例
    // {
    //     cout<<"Possible"<<endl;
    //     return;
    // }

    // if(cnt<n-1||cnt==n)
    // {
    //     cout<<"Impossible"<<endl;
    //     return;
    // }
    
    if(cnt<n-1)
    {
        cout<<"Impossible"<<endl;
        return;
    }

    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(d[i]&1) sum++;
    }
    if(sum!=0&&sum!=2)
    {
        cout<<"Impossible"<<endl;
        return;
    }

    cout<<"Possible"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/