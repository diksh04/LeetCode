/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left) 
            {
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            if(curr->right)
            {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markParents(root,parent);
        
        unordered_map<TreeNode*,bool>vis;
        vis[target] = true;
        queue<TreeNode*>q;
        q.push(target);
        int curlvl = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            if(curlvl++ == k) break;
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(parent[node] && !vis[parent[node]])
                {
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
        }
        
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};