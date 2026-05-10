class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        for(auto [x,y]:mp)
        {
            if(y>nums.size()/2) return x;
        }
        return 0;
    }
};