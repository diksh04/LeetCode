class Solution {
public:
    
    void bfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nrow = r + dRow[k];
                int ncol = c + dCol[k];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int countIsl=0;
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    countIsl++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return countIsl;
    }
};