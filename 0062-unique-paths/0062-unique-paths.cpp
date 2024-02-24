class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = helper(i-1,j,dp) + helper(i,j-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    temp[0] = 1;
                }
                else
                {
                    int left= 0,up=0;
                    if(i-1>=0)
                    {
                        up = prev[j];
                    }
                    if(j-1>=0)
                    {
                        left = temp[j-1];
                    }
                    temp[j] = left + up;
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};