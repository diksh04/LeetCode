class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int time = 0;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;
            time = max(t,time);
            for(int k=0;k<4;k++)
            {
                int nrow = r + dx[k];
                int ncol = c + dy[k];
                if(nrow>=0 && nrow < m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};