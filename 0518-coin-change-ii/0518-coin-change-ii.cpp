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
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int t=0;t<=amount;t++)
        {
            prev[t] = (t%coins[0]==0);
        }
        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                int notpick =  prev[t];
                int pick = 0;
                if(coins[i]<=t)
                {
                    pick = curr[t-coins[i]];
                }
                curr[t] = pick + notpick;
            }
            prev = curr;
        }
        return prev[amount];
    }
};