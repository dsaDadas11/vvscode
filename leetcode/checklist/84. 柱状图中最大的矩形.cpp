/*
 * @Author: dsaDadas11
 * @Date: 2025-09-02 13:34:13
 * @LastEditTime: 2025-09-02 13:34:18
 * @Description: go for it!
 */
class Solution {
public:
    vector<int> ls,rs,stk;
    int top;
    int ans;
    vector<int> a;
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        ls.clear(),rs.clear(),stk.clear();
        ls.resize(n+1),rs.resize(n+1),stk.resize(n+1);
        top=0,ans=0;
        a.clear();
        a.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            a[i]=heights[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            while(a[stk[top]]>a[i]&&top) top--;
            if(!top) ls[i]=stk[top+1];
            else ls[i]=rs[stk[top]],rs[stk[top]]=i;
            stk[++top]=i;
        }

        dfs(stk[1],1,n);

        return ans;
    }

    void dfs(int u,int l,int r)
    {
        ans=max(ans,a[u]*(r-l+1));
        if(ls[u])
        {
            dfs(ls[u],l,u-1);
        }
        if(rs[u])
        {
            dfs(rs[u],u+1,r);
        }
    }
};