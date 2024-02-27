class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>>dp(n+1,vector<long>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                long profit = 0;
                if(buy){
                    //buy
                    int webuy = -prices[idx] + dp[idx+1][0];
                    int notbuy = 0 + dp[idx+1][1];
                    profit = max(webuy,notbuy);
                }
                else
                {
                    //sell
                    int wesell = prices[idx] + dp[idx+1][1];
                    int notsell = 0 + dp[idx+1][0];
                    profit = max(wesell,notsell);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};