class Solution {
public:
    long helper(int idx,int amount,vector<int>& coins,vector<vector<long>>& dp)
    {
        if(idx==0)
        {
            return (amount%coins[0]==0);
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notpick =  helper(idx-1,amount,coins,dp);
        int pick = 0;
        if(coins[idx]<=amount)
        {
            pick = helper(idx,amount-coins[idx],coins,dp);
        }
        return dp[idx][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long>>dp(n,vector<long>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
    }
};