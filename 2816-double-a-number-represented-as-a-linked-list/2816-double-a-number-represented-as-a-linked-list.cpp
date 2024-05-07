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
    int helper(ListNode* temp)
    {
        if(temp == NULL)
        {
            return 0;
        }
        int carry = helper(temp->next);
        temp->val = temp->val * 2 + carry;
        if(temp->val < 10 )
        {
            return 0;
        }
        int val = temp->val / 10;
        temp->val = temp->val % 10;
        return val;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = helper(head);
        if(carry > 0)
        {
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};