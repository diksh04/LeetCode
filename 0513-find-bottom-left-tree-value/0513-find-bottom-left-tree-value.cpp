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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
        {
            return root->val;
        }
        queue<TreeNode*>q;
        q.push(root);
        int val = -1;
        while(!q.empty())
        {
            int n = q.size();
            vector<int>arr;
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                val = t->val;
                q.pop();
                if(t->right)
                {
                    q.push(t->right);
                    val = t->right->val;
                }
                if(t->left)
                {
                    q.push(t->left);
                    val = t->left->val;
                }
            }
        }
        return val;
    }
};