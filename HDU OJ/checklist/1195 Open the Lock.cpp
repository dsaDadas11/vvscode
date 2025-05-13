/*
 * @Author: dsaDadas11
 * @Date: 2025-04-23 22:24:20
 * @LastEditTime: 2025-04-29 19:26:11
 * @Description: go for it!
 */
/*
 双向 bfs, 920ms
 单向 bfs, 514ms
 题目大意：
 有一个四位数字组成的密码，为 1~9，可以在数字在减一或加1，9+1变为1，1-1变为9，相邻数字可以交换，求最小的开锁步骤

 解题思路：
 时间复杂度：
 最坏情况，遍历整个密码 1111~9999，约9000种，用单向bfs也可以，但是我们可以用这道题练习双向bfs
 注意密码进队列时需要去重
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
vector<int> s(4),t(4);
int vis[13][13][13][13];
int dist[13][13][13][13];
int bfs(queue<pair<vector<int>,int> > &q,int ord) // pwd step, order
{
    while(!q.empty())
    {
        auto [v,stp]=q.front();
        q.pop();
        if(vis[v[0]][v[1]][v[2]][v[3]]==ord) continue;
        else if(vis[v[0]][v[1]][v[2]][v[3]]==3-ord) return stp+dist[v[0]][v[1]][v[2]][v[3]];
        vis[v[0]][v[1]][v[2]][v[3]]=ord;
        dist[v[0]][v[1]][v[2]][v[3]]=stp;
        for(int i=0;i<4;i++)
        {
            vector<int> tmp(v.begin(),v.end());
            tmp[i]++;
            if(tmp[i]==10) tmp[i]=1;
            if(vis[tmp[0]][tmp[1]][tmp[2]][tmp[3]]==3-ord) return stp+dist[tmp[0]][tmp[1]][tmp[2]][tmp[3]]+1;
            q.push({tmp,stp+1});
        }
        for(int i=0;i<4;i++)
        {
            vector<int> tmp(v.begin(),v.end());
            tmp[i]--;
            if(tmp[i]==0) tmp[i]=9;
            if(vis[tmp[0]][tmp[1]][tmp[2]][tmp[3]]==3-ord) return stp+dist[tmp[0]][tmp[1]][tmp[2]][tmp[3]]+1;
            q.push({tmp,stp+1});
        }
        for(int i=0;i<3;i++)
        {
            vector<int> tmp(v.begin(),v.end());
            swap(tmp[i],tmp[i+1]);
            if(vis[tmp[0]][tmp[1]][tmp[2]][tmp[3]]==3-ord) return stp+dist[tmp[0]][tmp[1]][tmp[2]][tmp[3]]+1;
            q.push({tmp,stp+1});
        }
    }
    return 0;
}
int find_ans()
{
    queue<pair<vector<int>,int> > q,p;
    memset(vis,0,sizeof vis);
    memset(dist,0,sizeof dist);
    q.push({s,0});
    p.push({t,0});
    while(!q.empty()||!p.empty())
    {
        int ans;
        if(!q.empty())
        {
            ans=bfs(q,1);
            if(ans) return ans;
        }
        if(!p.empty())
        {
            ans=bfs(p,2);
            if(ans) return ans;
        }
    }
    return 0;
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<4;i++) s[i]=s1[i]-'0';
    for(int i=0;i<4;i++) t[i]=s2[i]-'0';
    cout<<find_ans()<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
/*
单向bfs: 
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
vector<int> s(4),t(4);
bool vis[13][13][13][13];
int ans;
void bfs()
{
    ans=0;
    queue<pair<vector<int>,int> > q; // pwd step
    memset(vis,0,sizeof vis);
    q.push({s,0});
    while(!q.empty())
    {
        auto [v,stp]=q.front();
        q.pop();
        if(v==t)
        {
            ans=stp;
            break;
        }
        if(vis[v[0]][v[1]][v[2]][v[3]]) continue;
        vis[v[0]][v[1]][v[2]][v[3]]=1;
        for(int i=0;i<4;i++)
        {
            vector<int> tmp(v.begin(),v.end());
            tmp[i]++;
            if(tmp[i]==10) tmp[i]=1;
            q.push({tmp,stp+1});
        }
        for(int i=0;i<4;i++)
        {
            vector<int> tmp(v.begin(),v.end());
            tmp[i]--;
            if(tmp[i]==0) tmp[i]=9;
            q.push({tmp,stp+1});
        }
        for(int i=0;i<3;i++)
        {
            vector<int> tmp(v.begin(),v.end());
            swap(tmp[i],tmp[i+1]);
            q.push({tmp,stp+1});
        }
    }
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<4;i++) s[i]=s1[i]-'0';
    for(int i=0;i<4;i++) t[i]=s2[i]-'0';
    bfs();
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