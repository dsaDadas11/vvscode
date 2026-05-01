/*
 * @Author: dsaDadas11
 * @Date: 2026-04-21 19:23:33
 * @LastEditTime: 2026-04-21 19:23:38
 * @Description: go for it!
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> mp;

        ListNode *pCurrent1=headA;
        while(pCurrent1!=NULL)
        {
            mp[pCurrent1]=1;
            pCurrent1=pCurrent1->next;
        }

        ListNode *pCurrent2=headB;
        while(pCurrent2!=NULL)
        {
            if(mp[pCurrent2])
            {
                return pCurrent2;
            }
            pCurrent2=pCurrent2->next;
        }

        return NULL;
    }
};