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
bool compare(TreeNode* a,TreeNode* b)
{
    return a->val < b->val;
}
class Solution {
public:
    vector<TreeNode*>ans;
    void helper(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        helper(root->left);
        ans.push_back(root);
        // cout<<root->val<<" ";
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        // 3 2 1
        // 1 2 3
        helper(root);
        vector<TreeNode*>res = ans;
        sort(res.begin(),res.end(),compare);
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]!=res[i])
            {
                swap(ans[i]->val,res[i]->val);
                // cout<<ans[i]->val<<endl;
                // cout<<res[i]->val<<endl;
                break;
            }
        }
        // 1 3 2 4
        // 1 2 3 4
    }
};
