class Solution {
public:
    int helper(int idx,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(idx==prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        int profit=0;
        if(buy){
            int webuy = -prices[idx] + helper(idx+1,0,cap,prices,dp);
            int notbuy = 0 + helper(idx+1,1,cap,prices,dp);
            profit = max(webuy,notbuy);
        }
        else
        {
            int wesell = prices[idx] + helper(idx+1,1,cap-1,prices,dp);
            int notsell = 0 + helper(idx+1,0,cap,prices,dp);
            profit = max(wesell,notsell);
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,1,k,prices,dp);
    }
};