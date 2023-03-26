class Solution {
public:
    void dfs(int node,vector<int>& dist_node,vector<bool>& visited,vector<int>& edges,int distance,int& ans,vector<bool>& extra)
    {
        if(node!=-1)
        {
            if(visited[node]!=1)
            {
                visited[node] = true;
                extra[node] = true;
                dist_node[node] = distance;
                dfs(edges[node],dist_node,visited,edges,distance+1,ans,extra);
            }
            else if(extra[node])
            {
                ans = max(ans,distance - dist_node[node]);
            }
            extra[node] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>dist_node(n,0);
        vector<bool>extra(n,false);
        vector<bool>visited(n,false);
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            if(visited[i]!=1)
            {
                dfs(i,dist_node,visited,edges,0,ans,extra);
            }
        }
        return ans;
    }
};