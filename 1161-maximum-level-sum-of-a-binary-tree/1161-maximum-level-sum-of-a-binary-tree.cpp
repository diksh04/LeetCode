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
    int maxLevelSum(TreeNode* root) {
        int ans = INT_MIN;
        int level = 0,lvl = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sum = 0;
            level++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            if(ans < sum)
            {
                ans = sum;
                lvl = level;
            }
        }
        return lvl;
    }
};