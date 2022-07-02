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
    ListNode* midNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL// even node
              && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy_node = new ListNode;
        ListNode* l3 = dummy_node;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val < l2->val)
            {
                l3->next = l1;
                l1=l1->next;
            }
            else
            {
                l3->next=l2;
                l2=l2->next;
            }
            l3=l3->next;
        }
        if(l1!=NULL)
        {
            l3->next = l1;
            l3=l3->next;
        }
        if(l2!=NULL)
        {
            l3->next = l2;
            l3=l3->next;
        }
        return dummy_node->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* mid = midNode(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return  mergeTwoLists(left,right);
    }
};