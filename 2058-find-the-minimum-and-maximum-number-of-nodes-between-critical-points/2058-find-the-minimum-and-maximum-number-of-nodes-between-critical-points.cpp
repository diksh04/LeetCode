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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        head = head->next;
        int i = 1;
        vector<int>arr;
        while(head->next)
        {
            if((prev->val < head->val && head->val > head->next->val) || (prev->val > head->val && head->val < head->next->val))
            {
                arr.push_back(i);
            }
            prev = head;
            head = head->next;
            i++;
        }
        if(arr.size()<2)
        {
            return {-1,-1};
        }
        int minDist = INT_MAX;
        for(int i=0;i<arr.size()-1;i++)
        {
            minDist = min(minDist,arr[i+1]-arr[i]);
        }
        return {minDist,arr.back()-arr[0]};
    }
};