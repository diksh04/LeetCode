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
    void countGoodNodes(TreeNode* root,int &count,int maxForThisStep)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val >= maxForThisStep)
        {
            count++;
            maxForThisStep = root->val;
        }
        countGoodNodes(root->left,count,maxForThisStep);
        countGoodNodes(root->right,count,maxForThisStep);
    }
    int goodNodes(TreeNode* root) {
        //using dfs algo
        int count = 0;
        if(root==NULL)
        {
            return count;
        }
        int mx = root->val;//maxValue till now
        countGoodNodes(root,count,mx);
        return count;
    }
};