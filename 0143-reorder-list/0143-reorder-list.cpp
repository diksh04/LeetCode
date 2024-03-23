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
// 2<-1->3->4
class Solution {
public:
    ListNode* rev(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        ListNode *curr = head,*prev = NULL;
        while(curr!=NULL)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode *slow = head,*fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* revHalf = rev(slow);
        ListNode* curr = head;
        while(revHalf->next)
        {
            ListNode* tempFront = curr->next;
            curr->next = revHalf;
            ListNode* tempBack = revHalf->next;
            revHalf->next = tempFront;
            revHalf = tempBack;
            curr = tempFront;
        }
    }
};