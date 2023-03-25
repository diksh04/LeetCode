class Solution {
public:
    int dfs(vector<vector<int>>& adj,int i,vector<int>& visited)
    {
        visited[i] = 1;
        int ans = 1;
        for(auto it: adj[i])
        {
            if(visited[it]!=1)
            {
                ans+=dfs(adj,it,visited);
            }
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>visited(n,0);
        vector<int>clsize;
        for(int i=0;i<n;i++)
        {
            if(visited[i]!=1)
            {
                int ans = dfs(adj,i,visited);
                clsize.push_back(ans);
            }
        }
        long long ans = 0;
        long long t = 0;
        for(int i=0;i<clsize.size();i++)// 4 2 1
        {
            t+=clsize[i];//4,6,7
            ans+=(n-t)*clsize[i];//3*4,1*2, 
        }
        return ans;
    }
};