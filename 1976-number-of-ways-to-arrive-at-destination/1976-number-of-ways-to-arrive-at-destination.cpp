class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
    for(auto it:roads)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,
    greater<pair<long long,int>>>pq;
    pq.push({0,0});
    vector<long long>dist(n,1e15);
    vector<long long>ways(n,0);
    ways[0] = 1;
    dist[0] = 0;
    int mod = (int)(1e9+7);
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        long long dis = it.first;
        int node = it.second;
        for(auto it:adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;
            if(wt + dis < dist[adjNode])
            {
                dist[adjNode] = wt + dis;
                ways[adjNode] = ways[node];
                pq.push({wt+dis,adjNode});
            }
            else if(wt + dis == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
    }
};