class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,bool>>>adj(n);
        for(auto &conn: connections)
        {
            adj[conn[0]].push_back({conn[1],1});
            adj[conn[1]].push_back({conn[0],0});
        }
        int count = 0;
        vector<bool>visited(n,0);
        queue<int>q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto i:adj[u])
            {
                if(visited[i.first]==0)
                {
                    if(i.second==1)
                    {
                        count++;
                    }
                    q.push(i.first);
                    visited[i.first] = 1;
                }
            }
        }
        return count;
    }
};