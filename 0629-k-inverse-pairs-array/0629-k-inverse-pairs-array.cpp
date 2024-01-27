class Solution {
public:
    const int MOD = 1e9+7;
    int dp[1001][1001];
    int helper(int n,int k,vector<vector<int>>& dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(k==0)
        {
            return 1;
        }
        if(dp[n][k]!=-1)
        {
            return dp[n][k];
        }
        int totalInv = 0;
        for(int i=0;i<=min(n-1,k);i++)
        {
            totalInv = (totalInv%MOD + helper(n-1,k-i,dp)%MOD)%MOD; 
        }
        return dp[n][k] = totalInv;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        return helper(n,k,dp);
    }
};