class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
            {
                vis[i][0] = 1;
                q.push({i,0});
            }
            if(!vis[i][n-1] && grid[i][n-1]==1)
            {
                vis[i][n-1]=1;
                q.push({i,n-1});
            }
        }
        for(int j=0;j<n;j++)
            {
                if(!vis[0][j] && grid[0][j]==1)
                {
                    vis[0][j] = 1;
                    q.push({0,j});
                }
                if(!vis[m-1][j] && grid[m-1][j]==1)
                {
                    vis[m-1][j]=1;
                    q.push({m-1,j});
                }
            }
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        while(!q.empty())
        {
            auto it = q.front();
            int r = it.first;
            int c = it.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nRow = r + dx[i];
                int nCol = c + dy[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && !vis[nRow][nCol]
                  && grid[nRow][nCol]==1)
                {
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};