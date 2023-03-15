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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag = false;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            if(front->left)
            {
                if(flag==true)
                {
                    return false;
                }
                q.push(front->left);
            }
            else
            {
                flag = true;
            }
            if(front->right)
            {
                if(flag==true)
                {
                    return false;
                }
                q.push(front->right);
            }
            else
            {
                flag = true;
            }
        }
        return true;
    }
};