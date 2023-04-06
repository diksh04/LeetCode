class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
        {
            return false;
        }
        if(grid[i][j]==1)
        {
            return true;
        }
        grid[i][j] = 1;
        bool p1 = dfs(grid,i+1,j);
        bool p2 = dfs(grid,i,j+1);
        bool p3 = dfs(grid,i-1,j);
        bool p4 = dfs(grid,i,j-1);
        return p1 && p2 && p3 && p4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size(),n = grid[0].size();
        for(int i = 0;i < m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    count+=dfs(grid,i,j)?1:0;
                }
            }
        }
        return count;
    }
};