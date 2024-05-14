class Solution {
public:
    vector<int>dRow = {-1,0,1,0};
    vector<int>dCol = {0,-1,0,1};
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
        {
            return 0;
        }
        int originalVal = grid[i][j];
        grid[i][j] = 0;
        int maxgold = 0;
        for(int k=0;k<4;k++)
        {
            int nrow = i + dRow[k];
            int ncol = j + dCol[k];
            maxgold = max(maxgold,dfs(nrow,ncol,grid));
        }
        grid[i][j] = originalVal;
        return maxgold + originalVal;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                {
                    maxGold = max(maxGold,dfs(i,j,grid));
                }
            }
        }
        return maxGold;
    }
};