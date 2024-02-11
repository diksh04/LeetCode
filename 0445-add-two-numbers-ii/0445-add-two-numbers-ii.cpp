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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* t1 = reverseList(l1);
        ListNode* t2 = reverseList(l2);
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        while(t1!=NULL || t2!=NULL || carry!=0)
        {
            int sum = 0;
            if(t1) sum+=t1->val;
            if(t2) sum+=t2->val;
            sum+=carry;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            ptr->next = newNode;
            ptr = ptr->next;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        ListNode* head = reverseList(dummy->next);
        return head;
    }
};