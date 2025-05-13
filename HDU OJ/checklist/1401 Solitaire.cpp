/*
 * @Author: dsaDadas11
 * @Date: 2025-04-25 13:21:41
 * @LastEditTime: 2025-04-29 19:26:32
 * @Description: go for it!
 */
/*
 题目大意：
 在一个 8x8的方格中有四个相同的棋子，每个棋子可以上下左右移动，当碰到其他棋子时可以跳过这个棋子，问是否可以在8步内从起始位置走到最终位置，注意是多组输入

 解题思路：
 时间复杂度：
 最坏情况，遍历整个棋局，状态数 64*63*62*61，大约1600万种棋局，1.6e7，常数大一点就超时了
 因此要用双向bfs，四个棋每走一步有16种走法，时间复杂度为 2*16^4，约等于 13万，比上面的小很多了
 去重， char vis[8].....，1代表正向搜索过，2代表逆向搜索过，不能用 int，会 mle
 要注意棋子需要排序，不排序的话一个棋局会有多种表示
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
struct op
{
    pair<int,int> p[4];
    int stp;
};
op s,t;

// 用来标记四个点的坐标，要记得排序
char vis[8][8][8][8][8][8][8][8];
char check_vis(pair<int,int> *p)
{
    return vis[p[0].first][p[0].second][p[1].first][p[1].second][p[2].first][p[2].second][p[3].first][p[3].second];
}
void make_vis(pair<int,int> *p,int ord)
{
    vis[p[0].first][p[0].second][p[1].first][p[1].second][p[2].first][p[2].second][p[3].first][p[3].second]=(char)('0'+ord);
}

// 判断棋子是否出界
bool check_mp(pair<int,int> p)
{
    return p.first>=0&&p.first<8&&p.second>=0&&p.second<8;
}

// 存放四个棋子的坐标，判断每次移动是否重合
bool pos[8][8];
void make_pos(pair<int,int> *p)
{
    memset(pos,0,sizeof pos);
    for(int i=0;i<4;i++)
    {
        pos[p[i].first][p[i].second]=1;
    }
}
bool check_pos(pair<int,int> p)
{
    return pos[p.first][p.second];
}

bool bfs(queue<op> &q,int ord)
{
    while(!q.empty())
    {
        auto [p,stp]=q.front();
        q.pop();
        if(stp>=4) continue;
        if(check_vis(p)==(char)((3-ord)+'0')) return 1;
        make_pos(p);
        op tmp;
        tmp.stp=stp+1;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++) tmp.p[k]=p[k];
                tmp.p[i].first+=dx[j];
                tmp.p[i].second+=dy[j];
                if(!check_mp(tmp.p[i])) continue;
                bool flag=0;
                while(check_pos(tmp.p[i]))
                {
                    tmp.p[i].first+=dx[j];
                    tmp.p[i].second+=dy[j];
                    if(!check_mp(tmp.p[i]))
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag) continue;
                sort(tmp.p,tmp.p+4);
                if(check_vis(tmp.p)==(char)((3-ord)+'0')) return 1;
                if(check_vis(tmp.p)==(char)(ord+'0')) continue;
                make_vis(tmp.p,ord);
                q.push(tmp);
            }
        }
    }
    return 0;
}
void find_ans()
{
    memset(vis,'0',sizeof vis);
    queue<op> q,p;
    q.push(s);
    p.push(t);
    make_vis(s.p,1);
    make_vis(t.p,2);
    while(!q.empty()||!p.empty())
    {
        if(!q.empty())
        {
            if(bfs(q,1)) return cout<<"YES"<<endl,void();
        }
        if(!p.empty())
        {
            if(bfs(p,2)) return cout<<"YES"<<endl,void();
        }
    }
    cout<<"NO"<<endl;
}
void solve()
{
    // 多组输入
    while(cin>>s.p[0].first>>s.p[0].second>>s.p[1].first>>s.p[1].second>>s.p[2].first>>s.p[2].second>>s.p[3].first>>s.p[3].second)
    {
        for(int i=0;i<4;i++)
        {
            cin>>t.p[i].first>>t.p[i].second;
        }
        for(int i=0;i<4;i++)
        {
            // 都减 1 否则 vis数组大小不够用
            t.p[i].first--;
            t.p[i].second--;
            s.p[i].first--;
            s.p[i].second--;
        }
        s.stp=t.stp=0;
        sort(s.p,s.p+4);
        sort(t.p,t.p+4);
        find_ans();
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}