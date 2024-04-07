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
// 1 8 9
//   * 2
//     8
class Solution {
public:
    int helper(ListNode* temp)
    {
        if(temp==NULL) return 0;
        int carry = helper(temp->next);
        temp->val = temp->val*2 + carry;
        if(temp->val < 10)
        {
            return 0;
        }
        int left = temp->val / 10;
        temp->val = temp->val % 10;
        return left;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = helper(head);
        if(carry>0)
        {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};