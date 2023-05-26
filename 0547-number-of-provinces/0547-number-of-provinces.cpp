class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis)
    {
        vis[node] = true;
        for(auto nbr: adj[node])
        {
            if(!vis[nbr])
            {
                dfs(nbr,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
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
        vector<bool>vis(n,0);
        int countComps = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                countComps++;
                dfs(i,adj,vis);
            }
        }
        return countComps;
    }
};