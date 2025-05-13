/*
 * @Author: dsaDadas11
 * @Date: 2025-04-25 21:05:37
 * @LastEditTime: 2025-04-29 19:27:02
 * @Description: go for it!
 */
/*
 题目大意：
 3x3的棋盘中有8个棋子和一个空格，周围的棋子可以移动到空格中，求最小移动到目标棋局的步骤

 解题思路：
 我们可以把空格当成移动点，用空格来移动找目标棋局，每次bfs时找空格位置
 首先我们得记录棋局不重复，可以用set或者map打标记，
 我们构造 h函数可以用 1.棋子不在目标位置的个数
                    2.每个点到目标点的曼哈顿距离之和  （更优）

*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dx[7]={0,1,0,-1};
int dy[7]={1,0,-1,0};
vector<vector<int> > t(5,vector<int>(5));
vector<vector<int> > s(5,vector<int>(5));
void init()
{
    t[1][1]=1,t[1][2]=2,t[1][3]=3;
    t[2][1]=8,t[2][2]=0,t[2][3]=4;
    t[3][1]=7,t[3][2]=6,t[3][3]=5;
}
int h(vector<vector<int> > a) // 计算 h函数
{
    int ans=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(a[i][j]!=t[i][j]) ans++;
        }
    }
    return ans;
}
struct op
{
    vector<vector<int> > a;
    int stp;
    bool operator<(const op&that) const
    {
        return stp+h(a)>that.stp+h(that.a);
    }
};
bool check(int x,int y)
{
    return x>=1&&x<=3&&y>=1&&y<=3;
}
void bfs()
{
    priority_queue<op> pq;
    set<vector<vector<int> > > se; // 记录棋局是否被访问
    pq.push({s,0});
    while(!pq.empty())
    {
        vector<vector<int> > v=pq.top().a;
        int stp=pq.top().stp;
        pq.pop();
        if(h(v)==0) return cout<<stp<<endl,void();
        int fx,fy;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(!v[i][j]) fx=i,fy=j;
            }
        }
        for(int i=0;i<4;i++)
        {
            int xx=fx+dx[i];
            int yy=fy+dy[i];
            if(!check(xx,yy)) continue;
            swap(v[fx][fy],v[xx][yy]);
            if(!se.count(v))
            {
                se.insert(v);
                pq.push({v,stp+1});
            }
            swap(v[fx][fy],v[xx][yy]);
        }
    }
}
void solve()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            char c;
            cin>>c;
            s[i][j]=c-'0';
        }
    }
    bfs();
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}