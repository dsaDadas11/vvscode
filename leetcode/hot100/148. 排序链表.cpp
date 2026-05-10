/*
 * @Author: dsaDadas11
 * @Date: 2026-05-05 19:01:19
 * @LastEditTime: 2026-05-05 19:01:24
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
    int b[(int)5e4+3]={0};
    vector<int> a{0};
    int n;
    void merge(int l,int mid,int r)
    {
        int k=l,i=l,j=mid+1;
        while(i<=mid&&j<=r)
        {
            if(a[i]<a[j]) b[k++]=a[i++];
            else b[k++]=a[j++];
        }
        while(i<=mid) b[k++]=a[i++];
        while(j<=r) b[k++]=a[j++];
        for(int i=l;i<=r;i++) a[i]=b[i];
    }
    void merge_sort(int l,int r)
    {
        if(l>=r) return;
        int mid=(l+r)>>1;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,mid,r);
    }

    ListNode* sortList(ListNode* head) {
        ListNode *pCurrent=head;
        while(pCurrent!=NULL)
        {
            a.push_back(pCurrent->val);
            pCurrent=pCurrent->next;
        }
        n=a.size()-1;

        merge_sort(1,n);
        pCurrent=new ListNode();
        pCurrent->next=NULL;
        head=pCurrent;
        for(int i=1;i<=n;i++)
        {
            ListNode* pTmp=new ListNode(a[i]);
            pTmp->next=NULL;
            pCurrent->next=pTmp;
            pCurrent=pTmp;
        }
        head=head->next;
        return head;
    }
};