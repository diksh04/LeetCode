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
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return -1;
        }
        int lch = height(root->left);
        int rch = height(root->right);
        int mx = max(lch,rch);
        return mx+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int lh = diameterOfBinaryTree(root->left);
        int rh = diameterOfBinaryTree(root->right);
        int h = height(root->left)+height(root->right)+2;
        int mx  = max(h,max(lh,rh));
        return mx;
    }
};