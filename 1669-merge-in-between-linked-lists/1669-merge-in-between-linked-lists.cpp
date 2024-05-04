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
        while(cnt < a && ptr1->next!=NULL)
        {
            ptr1 = ptr1->next;
            cnt++;
        }
        ListNode* end1 = ptr1;
        while(cnt<=b && ptr1->next!=NULL)
        {
            ptr1 = ptr1->next;
            cnt++;
        }
        ListNode* end2 = ptr1->next;
        ListNode* ptr = list2;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        end1->next = list2;
        ptr->next = end2;
        return list1;
    }
};