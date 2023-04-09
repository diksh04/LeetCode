class Solution {
public:
    bool isCyclic(vector<vector<int>>& adj,vector<int>& visited,int curr)
    {
        if(visited[curr]==2)
        {
            return true;
        }
        visited[curr] = 2;
        for(int i=0;i<adj[curr].size();i++)
        {
            if(visited[adj[curr][i]]!=1)
            {
                if(isCyclic(adj,visited,adj[curr][i]))
                {
                    return true;
                }
            }
        }
        visited[curr] = 1;
        return false;
    }
    bool containsCycle(vector<vector<int>>& adj,int n)
    {
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                if(isCyclic(adj,visited,i))
                {
                    return true;
                }
            }
        }
        return false;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>>adj(n);
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        if(containsCycle(adj,n))
        {
            return -1;
        }
        vector<int>indegree(n,0);
        for(auto x:edges)
        {
            indegree[x[1]]++;
        }
        vector<vector<int>>count(n,vector<int>(26,0));
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                count[i][colors[i]-'a']++;   
            }
        }
        int ans=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int r=*max_element(count[p].begin(),count[p].end());
            ans=max(ans,r);
            for(auto v: adj[p]){
                for(int i=0;i<26;i++){
                    count[v][i]=max(count[v][i],count[p][i]+(i==colors[v]-'a'));
                }
                if(--indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return ans;
    }
};