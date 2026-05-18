/*
 * @Author: dsaDadas11
 * @Date: 2026-05-17 19:18:35
 * @LastEditTime: 2026-05-17 19:22:19
 * @Description: go for it!
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> se;
        for(auto i:nums)
        {
            se.insert(i);
        }

        int ans=0;
        for(auto i:se)
        {
            if(se.count(i-1)) continue;
            int cnt=1;
            while(se.count(i+1)) i++,cnt++;
            ans=max(ans,cnt);
        }
        return ans;
        
    }
};