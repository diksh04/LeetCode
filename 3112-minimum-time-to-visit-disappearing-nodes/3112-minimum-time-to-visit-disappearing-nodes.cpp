class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>>adj(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>dist(n,1e9);
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();
            if(dis > dist[node]) continue;//we will never consider dis greater than our prev distance
            for(auto nbr:adj[node])
            {
                int edW = nbr.second;
                int adjNode = nbr.first;
                if(disappear[adjNode] > edW + dis && dist[adjNode] > edW + dis)
                {
                    pq.push({edW+dis,adjNode});
                    dist[adjNode] = edW + dis;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};