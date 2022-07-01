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
    int length(ListNode* head)
    {
        int count=0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* reverseK(ListNode* head,int k,int len)
    {
        if(len<k)
        {
            return head;
        }
        int count = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp=NULL;
        while(count<k && curr!=NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count++;
        }
        if(temp!=NULL)
        {
            head->next = reverseK(temp,k,len-k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       int len = length(head);
        return reverseK(head,k,len);
    }
};