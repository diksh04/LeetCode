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
    //searialization is used in this question which means converting a tree into string
    string helper(TreeNode* root,unordered_map<string,int>& umap,vector<TreeNode*>& ans)
    {
        if(root==NULL)
        {
            return "#";
        }
        string left = helper(root->left,umap,ans);
        string right = helper(root->right,umap,ans);
        string s = left + "," + right + "," + to_string(root->val);
        if(umap[s]==1)
        {
            ans.push_back(root);
        }
        umap[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>umap;
        vector<TreeNode*>ans;
        helper(root,umap,ans);
        return ans;
        //Time complexity will O(N^2) because there are N nodes and No strings
        //try to solve using O(N)
    }
};