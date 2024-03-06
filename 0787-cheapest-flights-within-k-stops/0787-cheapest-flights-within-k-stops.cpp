class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});//stops,src,dist
        vector<int>dist(n,1e7);
        dist[src] = 0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops > k) continue;
            for(auto it:adj[node])
            {
                int price = it.second;
                int adjNode = it.first;
                if(cost + price < dist[adjNode] && stops<=k)
                {
                    dist[adjNode] = cost + price;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==1e7) return -1;
        return dist[dst];
    }
};