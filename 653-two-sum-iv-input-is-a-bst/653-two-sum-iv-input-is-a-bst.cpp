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
    bool findTarget(TreeNode* root, int k) {
        helper(root);
        int i=0,j=ans.size()-1;
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        while(i<j)
        {
           if(ans[i]+ans[j]==k)
           {
               return true;
           }
           else if(ans[i]+ans[j]>k)
           {
               j--;
           }
           else
           {
                i++;
           }
        }
        return false;
    }
};