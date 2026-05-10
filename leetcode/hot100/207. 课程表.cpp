#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n,m;
        // 严格沿用你的变量名 g / ind，1起始编号
        vector<int> g[2005];
        int ind[2005] = {0};
        
        n = numCourses;
        m = prerequisites.size();
        int u,v;
        for(int i=1;i<=m;i++)
        {
            // 力扣输入是0起始，和你源码一样+1转1起始
            u = prerequisites[i-1][0];
            v = prerequisites[i-1][1];
            u++,v++;
            g[v].push_back(u);
            ind[u]++;
        }

        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v:g[u])
            {
                ind[v]--;
                if(ind[v]==0) q.push(v);
            }
        }

        // 严格沿用你的判断逻辑
        for(int i=1;i<=n;i++)
        {
            if(ind[i]>0) return false;
        }
        return true;
    }
};