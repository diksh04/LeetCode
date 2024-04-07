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
    int helper(ListNode* temp,int &cnt)
    {
        if(temp->next==NULL)
        {
            if(temp->val == 0) return 0;
            return 1;
        }
        int value = helper(temp->next,cnt);
        cnt++;
        return (pow(2,cnt)*temp->val)+value; 
    }
    
    int getDecimalValue(ListNode* head) {
        int cnt = 0;
        return helper(head,cnt);
    }
};