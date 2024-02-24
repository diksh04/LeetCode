class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==triangle.size()-1)
        {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int down = triangle[i][j] + helper(i+1,j,triangle,dp);
        int diag = triangle[i][j] + helper(i+1,j+1,triangle,dp);
        return dp[i][j] = min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diag);
            }
        }
        return dp[0][0];
    }
};

// 2
// 3 4
// 6 5 7
// 4 1 8 3