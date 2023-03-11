/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree. *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>&ans,int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        int mid = l + (r-l)/2;
        TreeNode* temp = new TreeNode(ans[mid]);
        temp->left = helper(ans,l,mid-1);
        temp->right = helper(ans,mid+1,r);
        return temp;   
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        vector<int>ans;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        return helper(ans,0,ans.size()-1);
    }
};