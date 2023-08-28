class Solution {
public:
    int helper(int idx,int target,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(idx==0)
        {
            if(target%coins[0]==0)
            {
                return target/coins[0];
            }
            else
            {
                return 1e9;
            }
        }
        if(dp[idx][target]!=-1)
        {
            return dp[idx][target];
        }
        int notpick = 0 + helper(idx-1,target,coins,dp);
        int pick = INT_MAX;
        if(coins[idx]<=target)
        {
            pick = 1 + helper(idx,target-coins[idx],coins,dp);
        }
        return dp[idx][target] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = helper(n-1,amount,coins,dp);
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
};