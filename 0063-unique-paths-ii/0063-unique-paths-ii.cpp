class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0 || arr[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = helper(i-1,j,arr,dp);
        int right = helper(i,j-1,arr,dp);
        return dp[i][j] = left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(m-1,n-1,arr,dp);
    }
};