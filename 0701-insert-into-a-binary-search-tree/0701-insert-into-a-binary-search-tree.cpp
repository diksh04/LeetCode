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
    TreeNode* insertIntoBST(TreeNode* node, int val) {
        if(!node) return new TreeNode(val);
        TreeNode* root = node;
        while(true)
        {
            if(root->val > val)
            {
                if(root->left == NULL)
                {
                    root->left = new TreeNode(val);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if(root->right == NULL)
                {
                    root->right = new TreeNode(val);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return node;
    }
};