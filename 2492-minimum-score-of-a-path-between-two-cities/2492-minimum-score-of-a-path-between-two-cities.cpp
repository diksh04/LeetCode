class Solution {
public:
    int dfs(int node,int& ans,vector<vector<pair<int,int>>>& adj,vector<bool>& visited)
    {
        visited[node] = 1;
        for(auto [v,dis] : adj[node])
        {
            ans = min(ans,dis);
            if(visited[v]==0)
            {
                visited[v]=1;
                ans = min(ans,dfs(v,ans,adj,visited));
            }
        }
        return ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int,int>>>adj(n+1);
        vector<bool>visited(n+1,0);
        for(auto road: roads)
        {
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        dfs(1,ans,adj,visited);
        return ans;
    }
};