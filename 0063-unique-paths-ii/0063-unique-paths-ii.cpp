class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp)
    {
        if(i<0 || j<0 || obstacleGrid[i][j]==1)
        {
            return 0;
        }
        if(i==0 && j==0)
        {
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int left = helper(i,j-1,obstacleGrid,dp);
        int top = helper(i-1,j,obstacleGrid,dp);
        return dp[i][j] = left + top;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(m-1,n-1,obstacleGrid,dp);
    }
};