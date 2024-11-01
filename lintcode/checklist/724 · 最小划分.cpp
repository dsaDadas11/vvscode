/*
 * @Author: dsaDadas11
 * @Date: 2024-09-03 18:01:37
 * @LastEditTime: 2024-09-03 18:04:04
 * @Description: go for it!
 */
/*
 这是一道01背包的变形题，我们将背包的体积设为sum/2，将a[i]理解为体积和权值
 那么就转化为res=dp[sum/2]的最大值
 答案就为 abs((sum-res)-res)
*/
class Solution {
public:
    /**
     * @param nums: the given array
     * @return: the minimum difference between their sums 
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int C=sum/2;
        vector<int> dp(C+7,0);
        for(int i=0;i<n;i++)
        {
            for(int j=C;j>=nums[i];j--)
            {
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        return abs(2*dp[C]-sum);
    }
};