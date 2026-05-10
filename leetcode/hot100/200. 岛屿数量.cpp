/*
 * @Author: dsaDadas11
 * @Date: 2026-05-04 13:43:17
 * @LastEditTime: 2026-05-04 13:44:25
 * @Description: go for it!
 */
class Solution {
public:
    int dx[5]={0,1,0,-1};
    int dy[5]={1,0,-1,0};
    bool vis[307][307]={0};

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int cnt=0;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(vis[i][j]||grid[i][j]=='0') continue;
                cnt++;
                queue<pair<int,int> > q;
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty())
                {
                    auto [x,y]=q.front();
                    q.pop();
                    //  vis[x][y]=1;  为什么加了反而更快，玄学
                    for(int k=0;k<4;k++)
                    {
                        int xx=x+dx[k],yy=y+dy[k];
                        if(xx>=0&&xx<row&&yy>=0&&yy<col&&grid[xx][yy]=='1'&&!vis[xx][yy])
                            q.push({xx,yy}),vis[xx][yy]=1; // 一定要先标记再入队啊，不然会重复入队，或者在外面判断 if(vis[x][y]==1)
                    }
                }
            }
        }
        return cnt;
    }
};