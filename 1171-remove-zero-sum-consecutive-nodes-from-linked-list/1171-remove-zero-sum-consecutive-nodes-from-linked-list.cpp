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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        unordered_map<int,ListNode*>umap;
        umap[0] = dummy;
        int prefixSum = 0;
        dummy->next = head;
        while(head!=NULL)
        {
            prefixSum+=head->val;
            if(umap.find(prefixSum)!=umap.end())
            {
                ListNode* start = umap[prefixSum];
                ListNode* temp = start;
                int psum = prefixSum;
                while(temp!=head)
                {
                    temp = temp->next;
                    psum+=temp->val;
                    if(temp!=head)
                    {
                        umap.erase(psum);
                    }
                }
                start->next = head->next;
            }
            else
            {
                umap[prefixSum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};