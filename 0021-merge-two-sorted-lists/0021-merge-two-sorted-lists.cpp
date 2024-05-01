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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val <= p2->val)
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
        if(p1!=NULL)
        {
            ptr->next = p1;
        }
        if(p2!=NULL)
        {
            ptr->next = p2;
        }
        return dummy->next;
    }
};