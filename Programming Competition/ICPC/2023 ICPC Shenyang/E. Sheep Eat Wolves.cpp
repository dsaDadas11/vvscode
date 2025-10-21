/*
 * @Author: dsaDadas11
 * @Date: 2025-09-24 20:53:54
 * @LastEditTime: 2025-09-24 20:54:28
 * @Description: go for it!
 */
/*
 解题思路：
 用 bfs 加 记忆化搜索
 f[x][y][2] 表示 左边有 x只羊，y只狼，在 0左边/ 1右边 的步数
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y,p,q;
int f[107][107][2];
void solve()
{
    cin>>x>>y>>p>>q;
    memset(f,-1,sizeof f);
    f[x][y][0]=0;
    queue<array<int,3> > pq;
    pq.push({x,y,0});

    while(!pq.empty())
    {
        auto [tx,ty,tp]=pq.front();
        pq.pop();
        if(tx==0)
        {
            cout<<f[tx][ty][tp]<<endl;
            return;
        }

        if(tp==0)
        {
            for(int i=0;i<=min(p,tx);i++)
            {
                for(int j=0;j<=min(p-i,ty);j++)
                {
                    if(i+j>p) continue;
                    int lx=tx-i,ly=ty-j;
                    int rx=x-tx,ry=y-ty;
                    if(lx+q<ly&&i!=tx) continue;

                    if(f[lx][ly][1]==-1)
                    {
                        pq.push({lx,ly,1});
                        f[lx][ly][1]=f[tx][ty][0]+1;
                    }
                }
            }
        }
        else
        {
            for(int i=0;i<=min(p,x-tx);i++)
            {
                for(int j=0;j<=min(p-i,y-ty);j++)
                {
                    if(i+j>p) continue;
                    int lx=tx+i,ly=ty+j;
                    int rx=x-tx,ry=y-ty;
                    if(rx-i+q<ry-j&&i!=x-tx) continue;
                    
                    if(f[lx][ly][0]==-1)
                    {
                        pq.push({lx,ly,0});
                        f[lx][ly][0]=f[tx][ty][1]+1;
                    }
                }
            }
        }
    }

    cout<<-1<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}