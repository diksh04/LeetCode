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
    void reorderListHelper(ListNode* right,int floor,int size)
    {
        if(right==NULL)
          {
            return;
          }
          reorderListHelper(right->next,floor+1,size);
          if(floor>size/2)
          {
            ListNode* temp = left->next;
            left->next = right;
            right->next=temp;
            left=temp;
          }
          else if(floor ==size/2)
          {
            right->next = NULL;
          }
    }
    ListNode *left;
    void reorderList(ListNode* head) {
        left = head;
        int size = 0;
        ListNode* t=head;
        while(t!=NULL)
        {
          size++;
            t= t->next;
        }
        reorderListHelper(head,0,size);
    }
};