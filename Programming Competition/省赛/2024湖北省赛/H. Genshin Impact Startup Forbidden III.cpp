/*
 * @Author: dsaDadas11
 * @Date: 2025-05-03 15:13:45
 * @LastEditTime: 2025-05-03 15:46:06
 * @Description: go for it!
 */
/*
 解题思路：
 先找出孤立点，然后遍历非孤立点的自身、上、下、左、右位置 p，再找 p的五个位置，
 看 p的五个位置的贡献，因为非孤立点旁边一定有非孤立点，因此贡献一定大于 1
 因此我们找 p中大于 1的贡献的点 (一开始以为自身一定要加进去，其实不然，就因为这里卡了一个小时...)
 最后用 dfs即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
#define pll pair<int,int>
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int dx[7]={0,1,0,-1,0};
int dy[7]={1,0,-1,0,0};
int nx[17]={0,1,0,-1,0,2,0,-2,1,1,-1,-1};
int ny[17]={1,0,-1,0,2,0,-2,0,1,-1,1,-1};
int n,m,k;
int a[M][M];
bool st[M][M];
int add=10000;
bool outmap(int x,int y)
{
	return x<1||x>n||y<1||y>m;
}
vector<pll> v,p,tar;
void dfs(int x,int cnt)
{
	if(x==tar.size())
	{
		for(auto &[xx,yy]:p)
		{
			if(a[xx][yy]>0) return;
		}
		add=min(add,cnt);
		return;
	}
	if(cnt>=add) return;
	auto &[xx,yy]=tar[x];
	for(int d=0;d<=3;d++)
	{
        a[xx][yy]-=d;
		for(int k=0;k<4;k++)
		{
			int xxx=xx+dx[k];
			int yyy=yy+dy[k];
			if(outmap(xxx,yyy)) continue;
			a[xxx][yyy]-=d;
		}
		
		dfs(x+1,cnt+d);
		
        a[xx][yy]+=d;
		for(int k=0;k<4;k++)
		{
			int xxx=xx+dx[k];
			int yyy=yy+dy[k];
			if(outmap(xxx,yyy)) continue;
			a[xxx][yyy]+=d;
		}
	}
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y,val;
		cin>>x>>y>>val;
		a[x][y]=val;
		v.emplace_back(x,y);
	}
	
	int ans=0;
	// 先判断孤立点
	for(auto [x,y]:v)
	{
		bool flag=1;
		for(int k=0;k<12;k++)
		{
			int xx=x+nx[k];
			int yy=y+ny[k];
			if(outmap(xx,yy)) continue;
			if(a[xx][yy]>0) flag=0;
		}
		
		if(flag) ans+=a[x][y];
		else p.emplace_back(x,y);
	}
	
	for(auto [x,y]:p)
	{
		for(int k=0;k<5;k++)
		{
			int xx=x+dx[k];
			int yy=y+dy[k];
			if(outmap(xx,yy)) continue;
			int cnt=0;
			for(int j=0;j<5;j++)
			{
				int xxx=xx+dx[j];
				int yyy=yy+dy[j];
				if(outmap(xxx,yyy)) continue;
				if(a[xxx][yyy]>0) cnt++;
			}
			if(cnt>1) tar.emplace_back(xx,yy);
		}
	}
	sort(tar.begin(),tar.end());
	tar.erase(unique(tar.begin(),tar.end()),tar.end());

	dfs(0,0);
    if(add==10000) add=0;
	cout<<ans+add<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
#define pll pair<int,int>
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int dx[7]={0,1,0,-1,0};
int dy[7]={1,0,-1,0,0};
int nx[17]={0,1,0,-1,0,2,0,-2,1,1,-1,-1};
int ny[17]={1,0,-1,0,2,0,-2,0,1,-1,1,-1};
int n,m,k;
int a[M][M];
bool st[M][M];
int add=10000;
bool outmap(int x,int y)
{
	return x<1||x>n||y<1||y>m;
}
vector<pll> v,tar,t;
void dfs(int x,int cnt)
{
	if(x==tar.size())
	{
		for(auto &[xx,yy]:t)
		{
			if(a[xx][yy]>0) return;
		}
		add=min(add,cnt);
		return;
	}
	if(cnt>=add) return;
	auto &[xx,yy]=tar[x];
	for(int d=0;d<=3;d++)
	{
        a[xx][yy]-=d;
		for(int k=0;k<4;k++)
		{
			int xxx=xx+dx[k];
			int yyy=yy+dy[k];
			if(outmap(xxx,yyy)) continue;
			a[xxx][yyy]-=d;
		}
		
		dfs(x+1,cnt+d);
		
        a[xx][yy]+=d;
		for(int k=0;k<4;k++)
		{
			int xxx=xx+dx[k];
			int yyy=yy+dy[k];
			if(outmap(xxx,yyy)) continue;
			a[xxx][yyy]+=d;
		}
	}
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y,val;
		cin>>x>>y>>val;
		a[x][y]=val;
		v.emplace_back(x,y);
	}
	
	int ans=0;
	// 先判断孤立点
    vector<tuple<int,int,int> > p;
	for(auto [x,y]:v)
	{
		for(int i=0;i<5;i++)
        {
            int ax=x+dx[i];
            int ay=y+dy[i];
            if(outmap(ax,ay)) continue;
            int cnt=0;
            for(int j=0;j<5;j++)
            {
                int nx=ax+dx[j];
                int ny=ay+dy[j];
                if(outmap(nx,ny)) continue;
                if(a[nx][ny]>0) cnt++;
            }
            p.push_back({ax,ay,cnt});
        }
	}
	
	sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());

    for(auto [x,y,c]:p)
    {
        if(c>1)
        {
            tar.emplace_back(x,y);
            for(int i=0;i<5;i++)
            {
                int ax=x+dx[i];
                int ay=y+dy[i];
                if(outmap(ax,ay)) continue;
                if(a[ax][ay]>0) st[ax][ay]=1;
            }
        }
    }
	
    for(auto [x,y]:v)
    {
        if(!st[x][y]) ans+=a[x][y];
        else t.emplace_back(x,y);
    }

	dfs(0,0);
    if(add==10000) add=0;
	cout<<ans+add<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/