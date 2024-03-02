class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<bool>>& vis)
    {
        vis[r][c] = true;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nRow = r + drow[i];
            int nCol = c + dcol[i];
            if(nRow>=0 && nRow<grid.size() && nCol>=0 && nCol<grid[0].size()
              && !vis[nRow][nCol] && grid[nRow][nCol]=='1')
            {
                dfs(nRow,nCol,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};