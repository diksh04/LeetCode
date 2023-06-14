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
    vector<int>ans;
    void helper(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        int res = INT_MAX;
        // 0 1 12 48 49
        for(int i=1;i<ans.size();i++)
        {
            res = min(res,abs(ans[i]-ans[i-1]));
        }
        return res;
    }
};