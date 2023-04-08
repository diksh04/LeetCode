/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>umap;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
        {
            return NULL;
        }
        Node* first = new Node(node->val,{});
        umap[node] = first;
        queue<Node*>q;
        q.push(node);
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            for(auto it:curr->neighbors)
            {
                if(!umap[it])
                {
                    umap[it] = new Node(it->val,{});
                    q.push(it);
                }
                umap[curr]->neighbors.push_back(umap[it]);
            }
        }
        return umap[node];
    }
};