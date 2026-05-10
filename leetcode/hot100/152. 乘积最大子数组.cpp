/*
 * @Author: dsaDadas11
 * @Date: 2026-05-05 18:03:33
 * @LastEditTime: 2026-05-05 18:10:40
 * @Description: go for it!
 */
class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(2)); // min max
        dp[0][0]=dp[0][1]=a[0];
        int maxn=a[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=min({dp[i-1][0]*a[i],dp[i-1][1]*a[i],a[i]});
            dp[i][1]=max({dp[i-1][0]*a[i],dp[i-1][1]*a[i],a[i]});
            maxn=max({maxn,dp[i][0],dp[i][1]});
        }
        return maxn;
    }
};