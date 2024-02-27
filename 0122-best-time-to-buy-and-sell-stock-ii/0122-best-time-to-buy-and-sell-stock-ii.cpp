class Solution {
public:
    long helper(int idx,int buy,vector<int>& prices,vector<vector<long>>& dp)
    {
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit = 0;
        if(buy){
            int webuy = -prices[idx] + helper(idx+1,0,prices,dp);
            int notbuy = 0 + helper(idx+1,1,prices,dp);
            profit = max(webuy,notbuy);
        }
        else
        {
            //sell
            int wesell = prices[idx] + helper(idx+1,1,prices,dp);
            int notsell = 0 + helper(idx+1,0,prices,dp);
            profit = max(wesell,notsell);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>>dp(n,vector<long>(2,-1));
        return (int)helper(0,1,prices,dp);
    }
};