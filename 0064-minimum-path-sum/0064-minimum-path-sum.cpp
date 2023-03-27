class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp)
    {
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        if(i<0 || j<0)
        {
            return 1e9;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int lsum = grid[i][j] + helper(grid,i-1,j,dp);
        int rsum = grid[i][j] + helper(grid,i,j-1,dp);
        dp[i][j] = min(lsum,rsum);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(grid,m-1,n-1,dp);
    }
};