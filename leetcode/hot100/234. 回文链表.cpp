/*
 * @Author: dsaDadas11
 * @Date: 2026-04-22 15:10:27
 * @LastEditTime: 2026-04-22 15:10:32
 * @Description: go for it!
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode *pCurrent=head;
        while(pCurrent!=NULL)
        {
            v.push_back(pCurrent->val);
            pCurrent=pCurrent->next;
        }

        int l=0,r=v.size()-1;
        while(l<=r)
        {
            if(v[l]!=v[r]) return 0;
            l++,r--;
        }
        return 1;
    }
};