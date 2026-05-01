/*
 * @Author: dsaDadas11
 * @Date: 2026-04-22 15:26:02
 * @LastEditTime: 2026-04-22 16:09:18
 * @Description: go for it!
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<>());
        return nums[k-1];
    }
};

/*
快排找第 k小：
class Solution {
public:
    int qnth(int l,int r,vector<int>& nums,int k)
    {
        if(l==r) return nums[l];

        int i=l-1,j=r+1,x=nums[(l+r)/2];
        while(i<j)
        {
            do i++; while(nums[i]<x);
            do j--; while(x<nums[j]);
            if(i<j) swap(nums[i],nums[j]);
        }

        if(k-1<=j) return qnth(l,j,nums,k);
        else return qnth(j+1,r,nums,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k+1;
        return qnth(0,nums.size()-1,nums,k);
    }
};
*/