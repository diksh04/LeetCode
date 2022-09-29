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
    int findHeight(TreeNode* root,int data)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->val!=data)
        {
            return 0;
        }
        return 1+max(findHeight(root->left,data),findHeight(root->right,data));
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int lmax = findHeight(root->left,root->val);
        int rmax = findHeight(root->right,root->val);
        return max(lmax+rmax ,max(longestUnivaluePath(root->left),longestUnivaluePath(root->right)));
    }
};