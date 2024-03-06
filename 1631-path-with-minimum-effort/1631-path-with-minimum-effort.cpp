class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;//diff,row,col
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e7));
        dist[0][0] = 0;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == n-1 && c == m-1) return diff;
            for(int k=0;k<4;k++)
            {
                int nrow = dx[k] + r;
                int ncol = dy[k] + c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int newEffort =max(abs(heights[nrow][ncol] - heights[r][c]),diff);
                    if(newEffort < dist[nrow][ncol]) 
                    {
                        dist[nrow][ncol] = newEffort;   
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
                                       return 0;
    }
};