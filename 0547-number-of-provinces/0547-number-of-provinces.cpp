class Solution {
public:
    void dfs(int node,vector<bool>& vis,vector<vector<int>>& adj)
    {
        vis[node] = true;
        for(auto ch:adj[node])
        {
            if(!vis[ch])
            {
                dfs(ch,vis,adj);
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
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};