class Solution {
public:
    int helper(int idx,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(idx==prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        int profit = 0;
        if(buy){
            int webuy = -prices[idx] + helper(idx+1,0,cap,prices,dp);
            int notbuy = 0 + helper(idx+1,1,cap,prices,dp);
            profit = max(webuy,notbuy);
        }
        else
        {
            int wesell = prices[idx] + helper(idx+1,1,cap-1,prices,dp);//transaction is completed therefore we sell
            int notsell = 0 + helper(idx+1,0,cap,prices,dp);
            profit = max(wesell,notsell);
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // dp[n][buy->0/1][cap->0/1/2]  
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,1,2,prices,dp);
    }
};