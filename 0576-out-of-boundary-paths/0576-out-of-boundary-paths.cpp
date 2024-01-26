class Solution {
public:
    int mod = 1000000007;
    int helper(int i,int j,int m,int n,int maxMove,vector<vector<vector<int>>>& dp)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return 1;
        }
        if(dp[i][j][maxMove]!=-1)
        {
            return dp[i][j][maxMove];
        }
        int left = 0,up = 0,down = 0,right = 0;
        if(maxMove > 0) 
        {
            left = helper(i-1,j,m,n,maxMove-1,dp);
        }
        if(maxMove > 0)
        {
            up = helper(i,j-1,m,n,maxMove-1,dp); 
        }
        if(maxMove > 0)
        {
            right = helper(i+1,j,m,n,maxMove-1,dp);
        }
        if(maxMove > 0)
        {
            down = helper(i,j+1,m,n,maxMove-1,dp);
        } 
        return dp[i][j][maxMove] = ((up+down)%mod + (left+right)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return helper(startRow,startColumn,m,n,maxMove,dp); 
    }
};