//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int threshold) {
        vector<pair<int,int>>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int cityNo = 0,cntCity = n;
        for(int i=0;i<n;i++)
        {
            vector<int>dist(n,1e9);
            dist[i] = 0;
            pq.push({0,i});
            while(!pq.empty())
            {
                auto it = pq.top();
                pq.pop();
                int dis = it.first;
                int node = it.second;
                for(auto it:adj[node])
                {
                    int adjNode = it.first;
                    int cost = it.second;
                    if(cost + dis < dist[adjNode])
                    {
                        dist[adjNode] = cost + dis;
                        pq.push({dist[adjNode],adjNode});
                    }
                }
            }
            int count = 0;
            for(int j=0;j<n;j++)
            {
                if(dist[j]<=threshold)
                {
                    count++;
                }
            }
            if(count<=cntCity)
            {
                cntCity = count;
                cityNo = i;
            }
        }
        return cityNo;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends