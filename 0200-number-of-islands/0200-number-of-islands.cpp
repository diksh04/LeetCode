class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<bool>>& vis)
    {
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]=='0' || vis[r][c]==true)
        {
            return;
        }
        vis[r][c] = true;
        dfs(r-1,c,grid,vis);
        dfs(r,c-1,grid,vis);
        dfs(r+1,c,grid,vis);
        dfs(r,c+1,grid,vis);
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
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};