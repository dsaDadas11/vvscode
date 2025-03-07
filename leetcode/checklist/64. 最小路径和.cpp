/*
 * @Author: dsaDadas11
 * @Date: 2025-03-04 18:07:01
 * @LastEditTime: 2025-03-04 18:07:06
 * @Description: go for it!
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > dp(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            if(i==0) dp[i][0]=grid[i][0];
            else dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int j=0;j<m;j++)
        {
            if(j==0) dp[0][j]=grid[0][j];
            else dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};