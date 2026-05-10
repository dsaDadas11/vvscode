/*
 * @Author: dsaDadas11
 * @Date: 2026-05-06 19:26:32
 * @LastEditTime: 2026-05-06 19:26:37
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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        do
        {
            if(fast==NULL||fast->next==NULL) return NULL;
            slow=slow->next;
            fast=fast->next->next;
        } while(slow!=fast);


        ListNode *pCurrent=head;
        while(pCurrent!=slow) // 一定会在入环点碰到
        {
            pCurrent=pCurrent->next;
            slow=slow->next;
        }
        return pCurrent;
    }
};