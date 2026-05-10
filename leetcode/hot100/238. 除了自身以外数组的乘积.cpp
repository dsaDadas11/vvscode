/*
 * @Author: dsaDadas11
 * @Date: 2026-05-05 16:35:33
 * @LastEditTime: 2026-05-05 16:35:38
 * @Description: go for it!
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int> pre(len);
        vector<int> suf(len);
        for(int i=0;i<len;i++)
        {
            if(i==0) pre[i]=nums[i];
            else pre[i]=pre[i-1]*nums[i];
        }
        for(int i=len-1;i>=0;i--)
        {
            if(i==len-1) suf[i]=nums[i];
            else suf[i]=suf[i+1]*nums[i];
        }
        vector<int> ans(len);
        ans[0]=suf[1];
        for(int i=1;i<len-1;i++)
        {
            ans[i]=pre[i-1]*suf[i+1];
        }
        ans[len-1]=pre[len-2];
        return ans;
    }
};