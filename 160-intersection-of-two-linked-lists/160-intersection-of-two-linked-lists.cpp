/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode* t)
    {
        ListNode* temp = t;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* one = headA;
        ListNode* two = headB;
        int c1 = len(headA);
        int c2 = len(headB);
        int res = abs(c1-c2);
        if(c1 > c2)
        {
            for(int i=0;i<res;i++)
            {
                one = one->next;
            }
        }
        else
        {
            for(int i=0;i<res;i++)
            {
                two = two->next;
            }
        }
        while(one!=two)
        {
            one = one->next;
            two = two->next;
        }
        return one;
    }
};