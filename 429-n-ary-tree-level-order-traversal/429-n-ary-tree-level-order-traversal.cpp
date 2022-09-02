/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
        {
            return {};
        }
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>res;
        while(q.size()>0)
        {
            vector<int>ans;
            int s = q.size();
            for(int i=0;i<s;i++)
            {
               Node* temp = q.front();
               q.pop();
                ans.push_back(temp->val);
                for(auto child:temp->children)
                {
                    q.push(child);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};