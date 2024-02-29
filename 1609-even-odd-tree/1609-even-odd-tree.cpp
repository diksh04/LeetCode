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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left)
                {
                    q.push(t->left);
                }
                if(t->right)
                {
                    q.push(t->right);
                }
            }
            if(level%2==0)
            {
                for(int i=0;i<temp.size();i++)
                {
                    if(temp[i]%2==0) return false;
                }
                for(int i=0;i<temp.size()-1;i++)
                {
                    if(temp[i]>=temp[i+1]) return false;
                }
            }
            else
            {
                for(int i=0;i<temp.size();i++)
                {
                    if(temp[i]%2==1) return false;
                }
                for(int i=0;i<temp.size()-1;i++)
                {
                    if(temp[i]<=temp[i+1]) return false;
                }
            }
            temp.empty();
            level++;
        }
        return true;
    }
};