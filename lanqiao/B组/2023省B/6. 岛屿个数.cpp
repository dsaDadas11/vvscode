/*
 * @Author: HuangCe
 * @Date: 2025-02-17 19:06:39
 * @LastEditTime: 2025-02-17 19:13:38
 * @Description: go for it!
 */
/*
 解题思路：
 bfs + 染色
 首先我们能找到岛屿个数，然后对每个岛屿进行八个方向的 bfs看是否能达到边界，
 如果可以，则不存在环
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dx[17]={0,-1,0,1,1,-1,-1,1};
int dy[17]={1,0,-1,0,1,1,-1,-1};
int n,m;
char ch[57][57];
int vis[57][57];
int sum;
void find_sum(int px,int py)
{
	queue<pair<int,int> > q;
	q.push({px,py});
	vis[px][py]=sum;
	while(!q.empty())
	{
		auto [x,y]=q.front();
		q.pop();
		if(ch[x][y]=='0') continue;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m) continue;
			if(ch[xx][yy]=='0') continue;
			if(vis[xx][yy]) continue;
			vis[xx][yy]=sum;
			q.push({xx,yy});
		}
	}
}
bool bfs(int x)
{
    queue<pair<int,int> > q;
    vector<vector<int> > di(57,vector<int>(57));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vis[i][j]==x)
            {
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        if(di[x][y]) continue;
        di[x][y]=1;
        if(x==1||x==n||y==1||y==m) return 1;
        for(int i=0;i<8;i++)
        {
            int xx=x+dx[i];
			int yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m) continue;
            if(di[xx][yy]) continue;
            if(ch[xx][yy]=='1') continue;
            q.push({xx,yy});
        }
    }
    return 0;
}
void solve()
{
	cin>>n>>m;
    sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
            cin>>ch[i][j];
            vis[i][j]=0;
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ch[i][j]=='0'||vis[i][j]) continue;
			sum++;
			find_sum(i,j);
		}
	}

    map<int,int> mp;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ch[i][j]=='0') continue;
            if(mp[vis[i][j]]) continue;
            mp[vis[i][j]]=1;
            if(!bfs(vis[i][j])) res++;
        }
    }
    cout<<sum-res<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}