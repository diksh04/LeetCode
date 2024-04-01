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
    ListNode* rev(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* dummy = new ListNode(0);
        l1 = rev(l1);
        l2 = rev(l2);
        int sum = 0,carry = 0;
        ListNode* ptr = dummy;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            sum = carry;
            if(l1)
            {
                sum+=l1->val;
            }
            if(l2)
            {
                sum+=l2->val;
            }
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            ptr->next = newNode;
            ptr = ptr->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        ptr = rev(dummy->next);
        return ptr;
    }
};