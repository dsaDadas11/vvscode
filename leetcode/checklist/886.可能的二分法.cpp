/*
 * @Author: HuangCe
 * @Date: 2025-02-25 18:58:06
 * @LastEditTime: 2025-02-25 18:58:14
 * @Description: go for it!
 */
class Solution {
public:
    bool dfs(int u,int c,vector<int>& color,vector<vector<int> >& g) {
        color[u]=c;
        for(auto v:g[u]) {
            if(!color[v]) {
                if(dfs(v,3-c,color,g)) {
                    return 1;
                }
            }
            else if(color[v]==c) return 1;
        }
        return 0;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,0);
        vector<vector<int> > g(n+1);
        for(auto p:dislikes) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for(int i=1;i<=n;i++) {
            if(color[i]) continue;
            if(dfs(i,2,color,g)) {
                return 0;
            }
        }
        return 1;
    }
};