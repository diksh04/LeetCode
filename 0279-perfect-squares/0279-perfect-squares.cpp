class Solution {
public:
    int helper(int n,vector<int>& dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int minCount = INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            int res = 1 + helper(n-i*i,dp);
            minCount = min(res,minCount);
        }
        return dp[n] = minCount;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};