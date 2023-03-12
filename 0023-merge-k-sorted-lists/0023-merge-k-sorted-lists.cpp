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
    ListNode* mergeTwoLists(ListNode* l,ListNode* r)
    {
        if(l==NULL)
        {
            return r;
        }
        if(r==NULL)
        {
            return l;
        }
        if(l->val <= r->val)
        {
            l->next = mergeTwoLists(l->next,r);
            return l;
        }
        else
        {
            r->next = mergeTwoLists(l,r->next);
            return r;

        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        {
            return NULL;
        }
        while(lists.size()>1)
        {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};