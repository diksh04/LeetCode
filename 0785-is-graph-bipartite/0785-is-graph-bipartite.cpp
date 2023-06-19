class Solution {
public:
    bool bfs(int start,vector<vector<int>>& graph,vector<int>& color)
    {
        queue<int>q;
        q.push(start);
        color[start] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto nbr:graph[node])
            {
                if(color[nbr]==-1)
                {
                    q.push(nbr);
                    color[nbr] = !color[node];
                }
                else if(color[nbr]==color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(i,graph,color)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};