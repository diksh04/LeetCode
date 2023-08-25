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
            return grid[grid.size()-1][j1];
        }
        else
        {
            return grid[grid.size()-1][j1] + grid[grid.size()-1][j2];
        }
    }
    // explore all paths
    if(dp[i][j1][j2]!=-1)
    {
        return dp[i][j1][j2];
    }
    int maxi = -1e9;
    for(int dj1 = -1;dj1<= 1;dj1++)//alice
    {
        for(int dj2 = -1;dj2<= 1;dj2++)//bob
        {
            int value = 0;
            if(j1==j2)
            {
                value = grid[i][j1];
            }
            else
            {
                value = grid[i][j1] + grid[i][j2];
            }
            value+=helper(i+1,j1+dj1,j2+dj2,grid,dp);
            maxi = max(maxi,value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(),c = grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return helper(0,0,c-1,grid,dp);
    }
};