class Solution {
public:
    void dfs(int src,vector<bool>& vis,vector<vector<int>>& adj)
    {
        vis[src] = true;
        for(auto nbr: adj[src])
        {
            if(!vis[nbr])
            {
                dfs(nbr,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // 1 1 0
        // 1 1 0
        // 0 0 1
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int countComps = 0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                countComps++;
                dfs(i,vis,adj);
            }
        }
        return countComps;
    }
};