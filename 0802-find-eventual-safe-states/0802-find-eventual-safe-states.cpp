class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis,vector<int>& pathVis,vector<int>& check)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for(auto nbr:graph[node])
        {
            if(!vis[nbr])
            {
                if(dfs(nbr,graph,vis,pathVis,check))
                {
                    check[nbr] = 0;
                    return true;
                }
            }
            else if(pathVis[nbr]==1)
            {
                check[nbr] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<int>safeNodes;
        vector<int>check(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,pathVis,check);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};