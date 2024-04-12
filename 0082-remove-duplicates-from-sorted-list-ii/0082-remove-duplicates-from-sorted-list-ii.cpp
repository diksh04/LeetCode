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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr->val!=curr->next->val)
            {
                prev->next = curr;
                curr = curr->next;
                prev = prev->next;
            }
            else
            {
                while(curr->next!=NULL && curr->val == curr->next->val)
                {
                    ListNode* duplicate = curr;
                    curr = curr->next;
                    delete duplicate;
                }
                curr = curr->next;
                prev->next = curr;

            }
        }
        return dummy->next;
    }
};

//   1->2->3->3->4->4->5
//      p              c
//   1->1
//p     c