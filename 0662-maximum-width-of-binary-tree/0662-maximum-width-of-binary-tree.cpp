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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*,int>>q;//node,index
        q.push({root,0});
        while(!q.empty())
        {
            int minm = q.front().second;
            int size = q.size();
            int first,last;
            for(int i=0;i<size;i++)
            {
                int cur_idx = q.front().second - minm;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0)
                {
                    first = cur_idx;
                }
                if(i==size-1)
                {
                    last = cur_idx;
                }
                if(node->left)
                {
                    q.push({node->left,(long long)2*cur_idx+1});
                }
                if(node->right)
                {
                    q.push({node->right,(long long)2*cur_idx+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};