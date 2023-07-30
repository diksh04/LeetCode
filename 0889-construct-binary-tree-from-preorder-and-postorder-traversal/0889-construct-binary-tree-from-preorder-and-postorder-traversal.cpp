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
    TreeNode* helper(vector<int>& preorder,int preStart,int preEnd,vector<int>& postorder,int postStart,int postEnd,map<int,int>& mp)
    {
        if(preStart > preEnd)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart==preEnd)
        {
            return root;
        }
        int postRoot = mp[preorder[preStart+1]];
        int numsLeft = postRoot-postStart;
        root->left = helper(preorder,preStart+1,preStart+numsLeft+1,postorder,postStart,postStart+numsLeft,mp);
        root->right = helper(preorder,preStart+numsLeft+2,preEnd,postorder,postStart+numsLeft+1,postEnd-1,mp);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<postorder.size();i++)
        {
            mp[postorder[i]] = i;
        }
        TreeNode* root = helper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,mp);
        return root;
    }
};