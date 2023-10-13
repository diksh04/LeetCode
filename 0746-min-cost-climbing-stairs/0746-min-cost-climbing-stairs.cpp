class Solution {
public:
    int helper(int idx,vector<int>& cost,vector<int>& dp)
    {
        if(idx<0) return 0;
        if(idx == 0)
        {
            return cost[0];
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        return dp[idx] = min(helper(idx-1,cost,dp),helper(idx-2,cost,dp))+cost[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(helper(n-1,cost,dp),helper(n-2,cost,dp));
    }
};