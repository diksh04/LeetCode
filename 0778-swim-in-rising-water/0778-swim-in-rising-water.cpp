class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        while(!pq.empty())
        {
            auto it = pq.top();
            int time = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            if(r==n-1 && c==n-1) return time;
            for(int k=0;k<4;k++)
            {
                int nrow = r + dx[k];
                int ncol = c + dy[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n)
                {
                    int newTime = grid[nrow][ncol] - time;
                    if(newTime > 0)
                    {
                        newTime+=time;
                    }
                    else newTime = time;
                    
                    if(dist[nrow][ncol] > newTime)
                    {
                        dist[nrow][ncol] = newTime;
                        pq.push({newTime,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};