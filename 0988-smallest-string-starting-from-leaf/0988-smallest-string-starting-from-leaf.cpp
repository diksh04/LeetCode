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
    string ans = "";
    void helper(TreeNode* root,string curr)
    {
        if(!root) return;
        curr = (char) (root->val + 'a') + curr;
        if(root->left==NULL && root->right==NULL)
        {
            if(ans=="" || ans > curr)
            {
                ans = curr;
            }
            return;
        }
        helper(root->left,curr);
        helper(root->right,curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        helper(root,"");
        return ans;
    }
};