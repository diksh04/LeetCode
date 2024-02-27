class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        // dp[n][buy->0/1][cap->0/1/2]  
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    int profit = 0;
                    if(buy){
                        int webuy = -prices[idx] + dp[idx+1][0][cap];
                        int notbuy = 0 + dp[idx+1][1][cap];
                        profit = max(webuy,notbuy);
                    }
                    else
                    {
                        int wesell = prices[idx] + dp[idx+1][1][cap-1];//transaction is completed therefore we sell
                        int notsell = 0 + dp[idx+1][0][cap];
                        profit = max(wesell,notsell);
                    }
                    dp[idx][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};