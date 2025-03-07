class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int mlen=0;
        for(int i=0;i<n;i++)
        {
            if(mlen<i) break;
            mlen=max(mlen,i+nums[i]);
            if(mlen>=n-1) return 1;
        }
        return 0;
    }
};