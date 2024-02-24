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
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else if(i==0 && j==0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int left = 0,top = 0;
                    if(i-1>=0)
                    {
                        top = dp[i-1][j]; 
                    }
                    if(j-1>=0)
                    {
                        left = dp[i][j-1];
                    }
                    dp[i][j] = left + top;
                }
            }
        }
        return dp[m-1][n-1];
    }
};