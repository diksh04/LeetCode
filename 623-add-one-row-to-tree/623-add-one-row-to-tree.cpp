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
    TreeNode* helper(TreeNode* root,int val,int depth,char c)
    {
        if(depth == 1)
        {
            TreeNode* node = new TreeNode(val);
            if(c == 'l')
            {
                node->left = root;
            }
            else
            {
                node->right = root;
            }
            return node;
        }
        if(root==NULL)
        {
            return NULL;
        }
        root->left=helper(root->left,val,depth-1,'l');
        root->right=helper(root->right,val,depth-1,'r');
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* node = new TreeNode;
            node->val = val;
            node->left = root;
            return node;
        }
        return helper(root,val,depth,'l');
    }
};