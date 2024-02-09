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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 1->2->3->4->5
//               s     f
        for(int i=0;i<n;i++)
        {
            fast = fast->next;
        }
        if(fast==NULL)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};