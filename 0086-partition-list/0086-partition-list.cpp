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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode *smallHead = small,*largeHead = large;
        while(head)
        {
            if(head->val < x)
            {
                smallHead->next = head;
                smallHead = smallHead->next;
            }
            else
            {
                largeHead->next = head;
                largeHead = largeHead->next;
            }
            head = head->next;
        }
        largeHead->next = NULL;
        smallHead->next = large->next;
        return small->next;
    }
};