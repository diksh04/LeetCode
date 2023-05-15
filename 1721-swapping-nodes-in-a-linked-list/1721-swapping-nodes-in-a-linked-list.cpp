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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* hed = head;
        ListNode* t1 = head;
        ListNode* t2 = head;
        ListNode* t3 = head;
        int size = 0;
        for(int i=0;i<k-1;i++)
        {
            t1 = t1->next;
        }
        while(t2!=NULL)
        {
            t2 = t2->next;
            size++;
        }
        for(int i=0;i<size-k;i++)
        {
            t3 = t3->next;
        }
        int temp = t1->val;
        t1->val = t3->val;
        t3->val = temp;
        return head;
    }
};