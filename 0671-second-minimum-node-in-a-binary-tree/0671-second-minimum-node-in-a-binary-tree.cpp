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
    void helper(TreeNode* root,long &first,long &second)
    {
        if(!root) return;
        if(root->val < first)
        {
            second = first;
            first  = root->val;
        }
        if(root->val > first && root->val < second)
        {
            second = root->val;
        }
        helper(root->left,first,second);
        helper(root->right,first,second);
    }
    int findSecondMinimumValue(TreeNode* root) {
        long first = LONG_MAX,second = LONG_MAX;
        helper(root,first,second);
        cout<<first<<" "<<second<<endl;
        return second == LONG_MAX ? -1 : second;
    }
};