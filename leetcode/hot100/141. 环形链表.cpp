/*
 * @Author: dsaDadas11
 * @Date: 2026-05-06 18:38:29
 * @LastEditTime: 2026-05-06 19:28:34
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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> mp;
        int cnt=0;
        while(head!=NULL)
        {
            if(mp.count(head))
            {
                return 1;
            }
            mp[head]=cnt++;
            head=head->next;
        }
        return 0;
    }
};

/*
快慢指针相遇必有环：
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return 0;
        ListNode *slow=head;
        ListNode *fast=head;
        do
        {
            if(fast==NULL||fast->next==NULL) return 0;
            slow=slow->next;
            fast=fast->next->next;
        } while(slow!=fast);
        return 1;
    }
};
*/