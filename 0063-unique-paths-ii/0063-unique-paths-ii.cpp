class Solution {
public:
    int helper(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp)
    {
        if(i>=m || j>=n || i<0 || j<0 || obstacleGrid[i][j]==1)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        dp[i][j] = helper(i+1,j,m,n,obstacleGrid,dp)+helper(i,j+1,m,n,obstacleGrid,dp);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(0,0,m,n,obstacleGrid,dp);
    }
};