/*
 * @Author: dsaDadas11
 * @Date: 2026-05-04 14:30:23
 * @LastEditTime: 2026-05-04 14:30:31
 * @Description: go for it!
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        constexpr int N=1e3+7;
        constexpr int M=2e3+7;
        int n;
        int a[N];
        int dp[N] = {0};
        
        n = nums.size();
        for(int i=1;i<=n;i++) {
            a[i] = nums[i-1];
        }

        dp[1]=a[1];
        for(int i=2;i<=n;i++)
        {
            dp[i]=max(dp[i-2]+a[i],dp[i-1]);
        }
        
        return dp[n];
    }
};