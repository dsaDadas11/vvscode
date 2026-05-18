/*
 * @Author: dsaDadas11
 * @Date: 2026-05-17 16:44:38
 * @LastEditTime: 2026-05-17 16:46:17
 * @Description: go for it!
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        for(auto [x,y]:mp)
        {
            if(y==1) return x;
        }
        return 0;
    }
};

/*
 因为只有一个数出现一次，那么可以使用异或
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            nums[i+1]^=nums[i];
        }
        return nums.back();
    }
};
*/