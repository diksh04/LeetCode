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
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++)
        {
            dp[0][t] = (t%coins[0]==0);
        }
        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                int notpick =  dp[i-1][t];
                int pick = 0;
                if(coins[i]<=t)
                {
                    pick = dp[i][t-coins[i]];
                }
                dp[i][t] = pick + notpick;
            }
        }
        return dp[n-1][amount];
    }
};