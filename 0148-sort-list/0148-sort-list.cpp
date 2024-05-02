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
    ListNode* merge(ListNode* list1,ListNode* list2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val < p2->val)
            {
                ptr->next = p1;
                p1 = p1->next;
            }
            else
            {
                ptr->next = p2;
                p2 = p2->next;
            }
            ptr = ptr->next;
        }
        if(p1!=NULL) ptr->next = p1;
        if(p2!=NULL) ptr->next = p2;
        return dummy->next;
    }
    ListNode* getMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* leftHead = head,*rightHead = mid->next;
        mid->next = NULL;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return merge(leftHead,rightHead);
    }
};