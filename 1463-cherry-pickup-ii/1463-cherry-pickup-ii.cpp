class Solution {
public:
    int helper(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
        {
            return -1e9;
        }
        if(i==grid.size()-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi = -1e9;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int val = 0;
                if(j1 == j2)
                {
                    val+=grid[i][j1];
                }
                else
                {
                    val = grid[i][j1] + grid[i][j2];
                }
                val+=helper(i+1,j1+dj1,j2+dj2,grid,dp);
                maxi = max(maxi,val);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int dp[n][m][m];
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                {
                    dp[n-1][j1][j2] = grid[n-1][j1];
                }
                else
                {
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int maxi = -1e9;
                    for(int dj1=-1;dj1<=1;dj1++)
                    {
                        for(int dj2=-1;dj2<=1;dj2++)
                        {
                            int val = 0;
                            if(j1==j2)
                            {
                                val+=grid[i][j1];
                            }
                            else
                            {
                                val+=grid[i][j1]+grid[i][j2];
                            }
                            if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
                            {
                                val+=dp[i+1][j1+dj1][j2+dj2];
                            }
                            else
                            {
                                val+=-1e9;
                            }
                            maxi = max(maxi,val);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};