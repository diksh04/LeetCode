class Solution {
public:
    void numberOfCities(int n,int src,vector<vector<pair<int,int>>>& adj,int distanceThreshold,vector<int> &citiesCount)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        pq.push({0,src});//distance source
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int node = it.second;
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                if(d + wt < dist[adjNode])
                {
                    dist[adjNode] = d + wt;
                    pq.push({d+wt,adjNode});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(i!=src && dist[i]<=distanceThreshold)
            {
                cnt++;
            }
        }
        citiesCount.push_back(cnt);
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>citiesCount;
        for(int i=0;i<n;i++)
        {
            numberOfCities(n,i,adj,distanceThreshold,citiesCount);
        }
        int miniCities = n;
        int cityNo = -1;
        for(int i=0;i<citiesCount.size();i++)
        {
            if(citiesCount[i]<=miniCities)
            {
                miniCities = citiesCount[i];
                cityNo = i;
            }
        }
        return cityNo;
    }
};