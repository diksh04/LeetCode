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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr1 = list1;
        int cnt = 1;
        while(cnt<a && ptr1->next!=NULL)
        {
            cnt++;
            ptr1 = ptr1->next; 
        }
        ListNode* end1 = ptr1;
    
        while(cnt<=b && ptr1->next!=NULL)
        {
            cnt++;
            ptr1 = ptr1->next;
        }
        ListNode* end2 = ptr1->next;
        end1->next = NULL;
        while(list2->next!=NULL)
        {
            end1->next = list2;
            end1 = end1->next;
            list2=list2->next;
        }
        list2->next = end2;
        return list1;
    }
};