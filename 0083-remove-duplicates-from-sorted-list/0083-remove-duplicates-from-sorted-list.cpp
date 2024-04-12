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
        if(head==NULL || head->next == NULL) return head;
        ListNode* temp = head;
        while(temp!=NULL && temp->next!=NULL)
        {
            ListNode* nextNode = temp->next;
            while(nextNode!=NULL && nextNode->val == temp->val)
            {
                ListNode* tempNode = nextNode;
                // cout<<tempNode->val<<" ";
                nextNode = nextNode->next;
                delete tempNode;
            }
            temp->next = nextNode;
            temp = temp->next;
        }
        return head;
    }
};