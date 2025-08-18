/*
 * @Author: dsaDadas11
 * @Date: 2025-07-21 18:27:46
 * @LastEditTime: 2025-07-21 18:31:36
 * @Description: go for it!
 */
/*
 解题思路：
 树的重心 + 点分治

 交互题可以关流
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int sz[N],root,mxs,sum;
int ms[N];
vector<int> g[N];
int ask(int u,int v)
{
    cout<<"? "<<u<<' '<<v<<endl;
    cout.flush();
    int res;
    cin>>res;
    return res;
}
void say(int u)
{
    cout<<"! "<<u<<endl;
    cout.flush();
}
void dfs(int u,int fax)
{
    sz[u]=1;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        ms[u]=max(ms[u],sz[v]);
    }
}
void get_root(int u,int fax)
{
    for(auto v:g[u])
    {
        if(v==fax) continue;
        get_root(v,u);
    }
    ms[u]=max(ms[u],sum-sz[u]);
    if(ms[u]<mxs) mxs=ms[u],root=u;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
        sz[i]=ms[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u)
        {
            g[i].push_back(u);
            g[u].push_back(i);
        }
        if(v)
        {
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }

    // 找重心，点分治
    int s=1; // 目前遍历到的点
    while(1)
    {
        for(int i=1;i<=n;i++) sz[i]=ms[i]=0;
        dfs(s,0); // 先预处理
        mxs=sum=sz[s];
        get_root(s,0);

        // 找到 root之后点分治
        if(g[root].empty())
        {
            say(root);
            break;
        }
        else if(g[root].size()==1)
        {
            int u=root,v=g[root][0];
            int res=ask(u,v);
            if(res==0)
            {
                say(u);
                break;
            }
            else
            {
                say(v);
                break;
            }
        }
        else
        {
            /*
             一个点最多有三个相邻结点，以 s遍历得到的 ms[i]是 i的最大子树大小
             设重心相邻的三个点为 a,b,c (ms[a]<ms[b]<ms[c])
             ms[c]是包括 root,a,b的最大子树，因此如果以 c往上分治则只需要遍历大约 ms[c]-ms[a]-ms[b]的大小
             而如果按 ms[c]进行左右分治的话，这个数量会非常大，
             因此需要 sort保证每次分治一定能砍掉至少一半的节点
            */
            sort(g[root].begin(),g[root].end(),[](auto &a,auto &b) {
                return ms[a]<ms[b];
            });
            int u=g[root][0],v=g[root][1];
            int res=ask(u,v);
            if(res==0)
            {
                s=u; // 往左分治
                g[s].erase(find(g[s].begin(),g[s].end(),root));
            }
            else if(res==2)
            {
                s=v; // 往右分治
                g[s].erase(find(g[s].begin(),g[s].end(),root));
            }
            else
            {
                s=root;// 往上分治
                g[s].erase(find(g[s].begin(),g[s].end(),u));
                g[s].erase(find(g[s].begin(),g[s].end(),v));
            }
        }
    }    
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}