/*
 * @Author: dsaDadas11
 * @Date: 2026-05-04 13:17:53
 * @LastEditTime: 2026-05-04 13:17:58
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
    ListNode* reverseList(ListNode* head) {
        //ListNode pPre=head;
        ListNode *pCurrent=head;
        ListNode *tHead=NULL;

        while(pCurrent!=NULL)
        {
            ListNode *tCurrent=new ListNode(*pCurrent);
            tCurrent->next=tHead;
            tHead=tCurrent;

            pCurrent=pCurrent->next;
        }

        return tHead;
    }
};