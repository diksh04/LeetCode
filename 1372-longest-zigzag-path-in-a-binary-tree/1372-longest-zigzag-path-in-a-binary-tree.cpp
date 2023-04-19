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
    int maxLen = 0;
    void helper(TreeNode* root,bool leftDir,int steps)
    {
        if(root==NULL)
        {
            return;
        }
        maxLen = max(maxLen,steps);
        if(leftDir)
        {
            helper(root->left,false,steps+1);
            helper(root->right,true,1);
        }
        else
        {
            helper(root->right,true,steps+1);
            helper(root->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        helper(root,true,0);
        helper(root,false,0);
        return maxLen;
    }
};