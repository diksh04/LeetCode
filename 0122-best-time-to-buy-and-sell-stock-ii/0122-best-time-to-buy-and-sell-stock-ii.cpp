class Solution {
public:
    int helper(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        int profit = 0;
        if(buy)
        {
            int weBuy = -prices[idx] + helper(idx+1,0,prices,dp);
            int notBuy = helper(idx+1,1,prices,dp);
            profit = max(weBuy,notBuy);
        }
        else
        {
            int weSell = prices[idx] + helper(idx+1,1,prices,dp);
            int notSell = helper(idx+1,0,prices,dp);
            profit = max(weSell,notSell);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                long profit = 0;
                if(buy == 1)
                {
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    profit = max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};