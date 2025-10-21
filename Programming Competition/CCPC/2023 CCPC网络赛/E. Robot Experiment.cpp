/*
 * @Author: dsaDadas11
 * @Date: 2025-09-17 20:36:41
 * @LastEditTime: 2025-09-17 20:38:05
 * @Description: go for it!
 */
/*
 解题思路：
 首先我们要判断这个点是不是新开拓的点，如果是就有两种选择，走 或者 定义为墙，不走
 如果不是新的点，那就看是不是往回走的路或者是墙
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string s;
set<pair<int,int> > se;
map<pair<int,int>,int> vis;
void dfs(int u,int x,int y)
{
    if(u==n+1)
    {
        se.insert({x,y});
        return;
    }

    int dx=0,dy=0;
    if(s[u]=='L') dx--;
    else if(s[u]=='R') dx++;
    else if(s[u]=='U') dy++;
    else dy--;

    if(!vis.count({x+dx,y+dy}))
    {
        vis[{x+dx,y+dy}]=1;
        dfs(u+1,x+dx,y+dy);
        vis[{x+dx,y+dy}]=2;
        dfs(u+1,x,y);
        vis.erase({x+dx,y+dy});
    }
    else if(vis[{x+dx,y+dy}]==2)
    {
        dfs(u+1,x,y);
    }
    else dfs(u+1,x+dx,y+dy);

}
void solve()
{
	cin>>n>>s;
	s=' '+s;
    vis[{0,0}]=1;
	dfs(1,0,0);
	cout<<se.size()<<endl;
	for(auto [x,y]:se) cout<<x<<' '<<y<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}