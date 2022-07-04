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
    vector<string>ans;
    void helper(TreeNode* root,string path)
    {
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(path);
            return;
        }
        if(root->left!=NULL)
        {
            helper(root->left,path+"->"+to_string(root->left->val));
        }
        if(root->right!=NULL)
        {
            helper(root->right,path+"->"+to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root,to_string(root->val));
        return ans;
    }
};