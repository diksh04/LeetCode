class Solution {
public:
    int helper(int idx,vector<int>& coins,int amount,vector<vector<int>>& dp)
    {
        if(idx==0)
        {
            if(amount%coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notpick = 0 + helper(idx-1,coins,amount,dp);
        int pick = 1e9;
        if(coins[idx]<=amount)
        {
            pick = 1 + helper(idx,coins,amount-coins[idx],dp);
        }
        return dp[idx][amount] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = helper(n-1,coins,amount,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};