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
    
    bool isPalindromeHelper(ListNode* right)
    {
        if(right==NULL)
        {
            return true;
        }
        bool res = isPalindromeHelper(right->next);
        if(res==false)
        {
            return false;
        }
        else if(pleft->val!=right->val)
        {
            return false;
        }
        else
        {
            pleft=pleft->next;
            return true;
        }
    }
    ListNode* pleft;
    bool isPalindrome(ListNode* head) {
        pleft = head;
     if(isPalindromeHelper(head)==true)
     {
         return true;
     }
    return false;
    }
};