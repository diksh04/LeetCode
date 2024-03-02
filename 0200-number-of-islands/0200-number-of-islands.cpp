class Solution {
public:
    void bfs(int r,int c,vector<vector<char>>& grid,vector<vector<bool>>& vis)
    {
        vis[r][c] = true;
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            int dRow[4] = {-1,0,1,0};
            int dCol[4] = {0,-1,0,1};
            for(int i=0;i<4;i++)
            {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if(nRow>=0 && nRow<grid.size() && nCol>=0 && nCol<grid[0].size() && !vis[nRow][nCol] && grid[nRow][nCol]=='1')
                {
                    vis[nRow][nCol] = true;
                    q.push({nRow,nCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};